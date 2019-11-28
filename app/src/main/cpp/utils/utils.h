//
// Created by JUN HU on 2019-11-26.
//

#ifndef OPENGLDEMO_UTILS_H
#define OPENGLDEMO_UTILS_H

#pragma once
#include <android/log.h>
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include <sys/types.h>
#include "../glm/vec4.hpp"
#include "../glm/ext.hpp"

typedef glm::mat4 mat4;
typedef glm::mat3 mat3;
typedef glm::vec3 vec3;
typedef glm::vec4 vec4;


#define LOGD(TAG, ...) __android_log_print(ANDROID_LOG_VERBOSE,TAG,__VA_ARGS__)

#define LOGE(TAG, ...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)


#endif //OPENGLDEMO_UTILS_H
