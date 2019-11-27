//
// Created by hu jun on 2019-11-26.
//
#include <cstdlib>
#include "AssetReader.h"
#include "../utils.h"

AAssetManager *aAssetManager = nullptr;

const char *readFromAsset(const char *path) {
    AAsset *asset = AAssetManager_open(aAssetManager, path, AASSET_MODE_UNKNOWN);
    if (asset == nullptr) {
        LOGE("AssetReader", "AAssetManager_open fail");
        return nullptr;
    }

    off_t size = AAsset_getLength(asset);
    char *data = static_cast<char *>(malloc(size + 1));
    data[size] = 0;
    AAsset_read(asset, data, size);
    LOGD("AssetReader", "read : %s", data);

    AAsset_close(asset);
    return data;
}
