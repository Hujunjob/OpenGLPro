//
// Created by JUN HU on 2019-11-26.
//

#include <android/log.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "opengl.h"
#include "native-lib.h"
#include "utils/AssetReader.h"

//定义顶点数组
float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
};

//顶点着色器会在GPU上创建内存，用于存储顶点数据
//需要配置OpenGL如何解释这些内存，指定如何发送给显卡
//通过顶点缓冲对象VBO来管理这个内存，在GPU内存（显存）中存储大量顶点
//这是从CPU发送到GPU，比较慢，所以尽量一次发送尽可能多的数据

//生成一个VBO对象，用一个id来表示
unsigned int VBO;

void generateVBO(){
    //生成一个VBO缓冲对象
    glGenBuffers(1,&VBO);

    //OpenGL有很多缓冲对象，VBO的缓冲类型是GL_ARRAY_BUFFER
    //同一种类型的缓冲对象只能绑定一个id
    //将VBO绑定到GL_ARRAY_BUFFER类型上
    glBindBuffer(GL_ARRAY_BUFFER,VBO);

    //当VBO被绑定到GL_ARRAY_BUFFER上时，所有操作GL_ARRAY_BUFFER的配置都是配置VBO了

    //接下来将顶点数据保存到VBO上，也就是保存到GL_ARRAY_BUFFER上
    //将数据保存到显存里，最后一个参数是保存方式，显卡如何管理这些数据
    //有三种管理方法
    //GL_STATIC_DRAW ：数据不会或几乎不会改变。
    //GL_DYNAMIC_DRAW：数据会被改变很多。
    //GL_STREAM_DRAW ：数据每次绘制时都会改变。
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW);
}

void initVertexShader(){
    const char* vShader = readFromAsset(aAssetManager,"");
}


void onSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
    LOGD("OpenGL", "onSurfaceChanged %d,%d", width, height);
}

void onSurfaceCreated() {
    LOGD("OpenGL", "onSurfaceCreated");
    generateVBO();
}

void onDrawFrame() {
    glClearColor(0.2, 0.3, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    LOGD("OpenGL", "onDrawFrame");
}
