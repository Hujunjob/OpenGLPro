//
// Created by JUN HU on 2019-11-27.
//

#include "Shader.h"



//动态编译顶点着色器源码
//创建着色器对象，还是用id存储
unsigned int generateVertexShader(const char *shader) {
    unsigned int vertexShaderId = 0;
    //创建shader
    vertexShaderId = glCreateShader(GL_VERTEX_SHADER);

    const char *vShader = readFromAsset(shader);
    //将着色器代码附着到着色器对象上
    glShaderSource(vertexShaderId, 1, &vShader, nullptr);

    //编译着色器代码
    glCompileShader(vertexShaderId);

    //检测是否编译成功
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShaderId, 512, nullptr, infoLog);
        LOGE("opengl", "generateVertexShader 编译顶点着色器错误 %s", infoLog);
    }
    return vertexShaderId;
}

//动态编译片段着色器
unsigned int generateFramgentShader(const char *shader) {
    unsigned int fragmentShaderId = 0;
    fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);


    const char *fShader = readFromAsset(shader);
    glShaderSource(fragmentShaderId, 1, &fShader, nullptr);
    glCompileShader(fragmentShaderId);

    int success;
    char infoLog[512];
    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShaderId, 512, nullptr, infoLog);
        LOGE("opengl", "generateVertexShader 编译片元着色器错误 %s", infoLog);
    }
    return fragmentShaderId;
}

//着色器程序是多个着色器合并后并最终链接在一起完成的版本
//链接多个着色器，会把一个着色器的输出当做另一个着色器的输入，如果输出输入不匹配，则会链接失败

unsigned int generateProgram(uint vShader, uint fShader) {
    //创建 --> 附着 --> 链接
    uint program = glCreateProgram();

    glAttachShader(program, vShader);
    glAttachShader(program, fShader);

    glLinkProgram(program);

    //检测
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char info[512];
        glGetProgramInfoLog(program, 512, nullptr, info);
        LOGE("opengl", "链接程序错误 %s", info);
        return 0;
    } else {
        LOGD("opengl", "链接成功");
        return program;
    }
}

uint linkProgram(const char*vShaderPath,const char* fShaderPath) {
    auto vShader = generateVertexShader(vShaderPath);
    if (vShader == 0) {
        LOGD("opengl", "linkProgram 顶点着色器生成失败");
        return 0;
    }
    auto fShader = generateFramgentShader(fShaderPath);
    if (fShader == 0) {
        LOGD("opengl", "linkProgram 片元着色器生成失败");
        return 0;
    }
    auto program = generateProgram(vShader, fShader);
    if (program == 0) {
        LOGD("opengl", "linkProgram 链接失败");
        return 0;
    }

    //激活程序对象，这样以后渲染都是调用这个着色器程序了
    glUseProgram(program);

    //删除
    glDeleteShader(vShader);
    glDeleteShader(fShader);

    return program;
}
