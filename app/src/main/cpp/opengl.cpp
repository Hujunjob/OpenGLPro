//
// Created by JUN HU on 2019-11-26.
//


#include "opengl.h"
#include "utils/Texture.h"
#include "glm/vec4.hpp"
#include "glm/ext.hpp"
#include "vertex/Cube.h"


const char *vShaderPath = "vtriangle.vert";
const char *fShaderPath = "ftriangle.glsl";

typedef glm::mat4 mat4;

Shader *shader;

int frameCount = 0;
//定义顶点数组
float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
};

float verticesTexture[] = {
//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // 右上
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,   // 左下
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f    // 左上
};

//只存储4个点，由索引指定绘制的顺序
float rectangleVertices[] = {
        0.5f, 0.5f, 0.0f,   // 右上角
        0.5f, -0.5f, 0.0f,  // 右下角
        -0.5f, -0.5f, 0.0f, // 左下角
        -0.5f, 0.5f, 0.0f   // 左上角
};

unsigned int indices[] = { // 注意索引从0开始!
        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
};

//位置和颜色全放在一个数组里
float vertexAndColor[] = {
        // 位置              // 颜色
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // 左下
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // 顶部
};


mat4 rotateByX(float angle){
    mat4 mat = glm::mat4(1.0f);
    mat = glm::rotate(mat,glm::radians(angle),glm::vec3(1.0f,0.0f,0.0f));
    return mat;
}


//模型矩阵，绕X轴旋转55°，相当于平躺55°下来
mat4 modelMatrix(){
    return rotateByX(-55.0f);
}

//观察矩阵，就是相机位置矩阵
mat4 viewMatrix(){
    mat4 mat = glm::mat4(1.0f);
    //相机往前移动一段距离观测，相当于整个场景往后移动
    mat = glm::translate(mat,glm::vec3(0.0f,0.0f,-3.0f));
    return mat;
}

mat4 projectionMatrix(){
    float fov = 45.0f;
    float respect = 720.0f/1280.0f;
    float near = 0.1f;
    float far = 100.0f;
    return glm::perspective(glm::radians(fov),respect,near,far);
}

//顶点着色器会在GPU上创建内存，用于存储顶点数据
//需要配置OpenGL如何解释这些内存，指定如何发送给显卡
//通过顶点缓冲对象VBO来管理这个内存，在GPU内存（显存）中存储大量顶点
//这是从CPU发送到GPU，比较慢，所以尽量一次发送尽可能多的数据

//生成一个VBO对象，用一个id来表示
unsigned int VBO;


//生成一个VAO对象
uint VAO;

uint texture1;
uint texture2;

uint EBO;

void drawCube();

void generateVBO() {
    //生成一个VBO缓冲对象
    glGenBuffers(1, &VBO);

    //OpenGL有很多缓冲对象，VBO的缓冲类型是GL_ARRAY_BUFFER
    //同一种类型的缓冲对象只能绑定一个id
    //将VBO绑定到GL_ARRAY_BUFFER类型上
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //当VBO被绑定到GL_ARRAY_BUFFER上时，所有操作GL_ARRAY_BUFFER的配置都是配置VBO了

    //接下来将顶点数据保存到VBO上，也就是保存到GL_ARRAY_BUFFER上
    //将数据保存到显存里，最后一个参数是保存方式，显卡如何管理这些数据
    //有三种管理方法
    //GL_STATIC_DRAW ：数据不会或几乎不会改变。
    //GL_DYNAMIC_DRAW：数据会被改变很多。
    //GL_STREAM_DRAW ：数据每次绘制时都会改变。
//    glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), rectangleVertices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTexture), verticesTexture, GL_STATIC_DRAW);

//    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


//由于顶点着色器允许指定各种形式的输入，所有我们需要让OpenGL知道如何读取这些数据
//例如我们当前的VBO是顶点数据以XYZ形式连续排列，所以顶点连续排列
void handleVBO() {
    //告诉OpenGL如何读取VBO数据
    //各个参数说明
//
//    第一个参数指定从索引0开始取数据，与顶点着色器中layout(location=0)对应。
//
//    第二个参数指定顶点属性大小，顶点属性是vec3，则由3个值xyz组成
//
//    第三个参数指定数据类型。
//
//    第四个参数定义是否希望数据被标准化（归一化），只表示方向不表示大小。
//
//    第五个参数是步长（Stride），指定在连续的顶点属性之间的间隔。
//
//    第六个参数表示我们的位置数据在缓冲区起始位置的偏移量。
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    //以上面的索引值0作为参数，启动顶点属性
//    glEnableVertexAttribArray(0);

//有两个属性需要赋值
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                          (void *) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

//矩形由2个三角形组成，需要6个点。但是有两个点重复了，浪费存储空间
//float rectangleVertices[] = {
//        // 第一个三角形
//        0.5f, 0.5f, 0.0f,   // 右上角
//        0.5f, -0.5f, 0.0f,  // 右下角
//        -0.5f, 0.5f, 0.0f,  // 左上角
//        // 第二个三角形
//        0.5f, -0.5f, 0.0f,  // 右下角
//        -0.5f, -0.5f, 0.0f, // 左下角
//        -0.5f, 0.5f, 0.0f   // 左上角
//};

void generateEBO() {
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}


//查找uniform变量的位置
//GLint colorLocation;

void changeUniform() {
    //根据时间变化的颜色
    struct timeval time;
    gettimeofday(&time, nullptr);
    double green = sin(time.tv_sec) * 0.5 + 0.5;
    //更新该uniform变量的值
//    glUniform4f(colorLocation, 0, green, 0, 1);
    shader->setUnifom4f("ourColor", 0, green, 0, 1);
}

void drawTriangle() {
//    glUseProgram(mProgram);
    shader->use();

//    glDrawArrays(GL_TRIANGLES, 0, 3);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBindVertexArray(VAO);
//    changeUniform();
//    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

glm::mat4 rotateAndScale() {
    glm::mat4 trans = glm::mat4(1);
//    mat = glm::rotate(mat, glm::radians(90.0F), glm::vec3(0.0, 0.0, 1.0));
//    mat = glm::scale(mat, glm::vec3(0.5, 0.5, 0.5));

    struct timeval xTime;
    gettimeofday(&xTime, nullptr);

    long long xFactor = 1;
    long long now = (long long)(( xFactor * xTime.tv_sec * 1000) + (xTime.tv_usec / 1000));

//    time.tv_usec
//    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    float angle = frameCount;
//    LOGD("rotateAndScale","angle=%f",angle);
    trans = glm::rotate(trans, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
    return trans;
}




glm::mat4 rotateAndScale2() {
    glm::mat4 trans = glm::mat4(1);
//    mat = glm::rotate(mat, glm::radians(90.0F), glm::vec3(0.0, 0.0, 1.0));
//    mat = glm::scale(mat, glm::vec3(0.5, 0.5, 0.5));

    struct timeval xTime;
    gettimeofday(&xTime, nullptr);

    long long xFactor = 1;
    long long now = (long long)(( xFactor * xTime.tv_sec * 1000) + (xTime.tv_usec / 1000));

//    time.tv_usec
    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    float angle = frameCount;
//    LOGD("rotateAndScale","angle=%f",angle);
    trans = glm::rotate(trans, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
    return trans;
}

void drawRectangle() {

    shader->use();
    glBindVertexArray(VAO);

//    glm::mat4 trans = rotateAndScale();
//    glm::mat4 trans = glm::mat4(1.0f);
    shader->setMatrix4fv("transform", glm::value_ptr(rotateByX(-45.0f)));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glm::mat4 trans2 = rotateAndScale2();
//    shader->setMatrix4fv("transform", glm::value_ptr(trans2));
//    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}


//以上绑定了一个三角形，但是如果我们有几十几百个物体，这样绑定和配置就太麻烦了
//使用顶点数组对象VAO Vertex Array Object，可以保存所有的VBO对象和配置
//利用VAO可以同时存储VBO和EBO
uint generateVAO() {
    uint vao = 0;
    //生成VAO
    glGenVertexArrays(1, &vao);

    //绑定VAO
    glBindVertexArray(vao);

    //生成VBO
    generateVBO();
    //告诉OpenGL如何解析VBO并启动VBO
    handleVBO();

    //生成绑定EBO
    generateEBO();

    //解绑VAO
    glBindVertexArray(0);
    return vao;
}

void initMatrix(){
    shader->setMatrix4fv("model",glm::value_ptr(modelMatrix()));
    shader->setMatrix4fv("view",glm::value_ptr(viewMatrix()));
    shader->setMatrix4fv("projection",glm::value_ptr(projectionMatrix()));
}


void onSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
    LOGD("OpenGL", "onSurfaceChanged %d,%d", width, height);
}

void onSurfaceCreated() {
    LOGD("OpenGL", "onSurfaceCreated");
    //将数据灌入显存
//    generateVBO();
//    generateEBO();
    shader = new Shader();

    texture1 = loadTexture("/sdcard/container.jpg");
    texture2 = loadTexture("/sdcard/awesomeface.png");

    VAO = generateVAO();

    //链接我们自定义的着色器
    shader->linkProgram(vShaderPath, fShaderPath);

    //需要告诉着色器，每个纹理对应片元着色器里的哪个uniform sampler2D
    shader->setUnifom1i("ourTexture", 0);
    shader->setUnifom1i("ourTexture2", 1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    initMatrix();

//    testGLM();
//    colorLocation = glGetUniformLocation(mProgram, "ourColor");
    //OpenGL ES里剔除了这个方法
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}


void onDrawFrame() {
    frameCount++;
//    if (frameCount % 4 != 0) {
//        return;
//    }
    glClearColor(0.2, 0.3, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    LOGD("OpenGL", "onDrawFrame");
//    drawTriangle();
//    drawRectangle();
    drawCube();

}

void drawCube() {
    shader->use();


}

