//
// Created by hu jun on 2019-11-26.
//

#ifndef OPENGLDEMO_ASSETREADER_H
#define OPENGLDEMO_ASSETREADER_H
#pragma once
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

extern AAssetManager *aAssetManager;

const char* readFromAsset(const char*);

#endif //OPENGLDEMO_ASSETREADER_H
