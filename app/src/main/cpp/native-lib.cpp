#include <jni.h>
#include <string>

#include "native-lib.h"
#include "opengl.h"
#include "utils/AssetReader.h"

extern "C" {
JNIEXPORT jstring JNICALL
Java_com_hujun_opengldemo_jni_Jni_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


JNIEXPORT void JNICALL
Java_com_hujun_opengldemo_jni_Jni_OnDrawFrame
        (JNIEnv *env, jobject) {
//    LOGD("Native","OnDrawFrame");
    onDrawFrame();
}


JNIEXPORT void JNICALL
Java_com_hujun_opengldemo_jni_Jni_onSurfaceChanged
        (JNIEnv *, jobject, jint width, jint height) {
//    LOGD("Native","onSurfaceChanged w=%d,h=%d",width,height);
    onSurfaceChanged(width, height);
}

JNIEXPORT void JNICALL
Java_com_hujun_opengldemo_jni_Jni_onSurfaceCreated
        (JNIEnv *, jobject) {
//    LOGD("Native","onSurfaceCreated");
    onSurfaceCreated();
}


JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_nativeSetAssetManager
        (JNIEnv *env, jobject, jobject jassetManager) {
    aAssetManager = AAssetManager_fromJava(env, jassetManager);
}

}