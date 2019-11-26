//
// Created by hu jun on 2019-11-26.
//

#ifndef OPENGLDEMO_ASSETREADER_H
#define OPENGLDEMO_ASSETREADER_H

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

const char* readFromAsset(AAssetManager *manager,const char*);

#endif //OPENGLDEMO_ASSETREADER_H
