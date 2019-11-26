//
// Created by JUN HU on 2019-11-26.
//

#ifndef OPENGLDEMO_UTILS_H
#define OPENGLDEMO_UTILS_H

#include <android/log.h>

#define LOGD(TAG, ...) __android_log_print(ANDROID_LOG_VERBOSE,TAG,__VA_ARGS__)

#define LOGE(TAG, ...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)


#endif //OPENGLDEMO_UTILS_H
