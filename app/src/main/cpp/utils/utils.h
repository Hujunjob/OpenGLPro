//
// Created by JUN HU on 2019-11-26.
//

#ifndef OPENGLDEMO_UTILS_H
#define OPENGLDEMO_UTILS_H

#pragma once
#include "../../../../../../../Library/Android/sdk/ndk/20.1.5948944/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/android/log.h"
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include <sys/types.h>

#define LOGD(TAG, ...) __android_log_print(ANDROID_LOG_VERBOSE,TAG,__VA_ARGS__)

#define LOGE(TAG, ...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)


#endif //OPENGLDEMO_UTILS_H
