//
// Created by JUN HU on 2019-11-27.
//

#ifndef OPENGLDEMO_SHADER_H
#define OPENGLDEMO_SHADER_H

#include "AssetReader.h"
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include <sys/types.h>
#include "../utils.h"

uint linkProgram(const char*vShaderPath,const char* fShaderPath);

#endif //OPENGLDEMO_SHADER_H
