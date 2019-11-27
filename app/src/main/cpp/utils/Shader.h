//
// Created by JUN HU on 2019-11-27.
//

#ifndef OPENGLDEMO_SHADER_H
#define OPENGLDEMO_SHADER_H

#pragma once
#include "AssetReader.h"
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include <sys/types.h>
#include "utils.h"

class Shader{
private:
    uint mProgram;

public:
    void linkProgram(const char*vShaderPath,const char* fShaderPath);
    //启动program
    void use();

    void setUnifom4f(const char* unifomName, float v1,float v2,float v3,float v4);
};



#endif //OPENGLDEMO_SHADER_H
