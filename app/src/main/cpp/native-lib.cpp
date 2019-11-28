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


/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    pressUp
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pressUp
        (JNIEnv *, jobject, jint value) {
    onPressUp(value);
}

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    pressDown
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pressDown
        (JNIEnv *, jobject, jint value) {
    onPressDown(value);
}

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    pressLeft
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pressLeft
        (JNIEnv *, jobject, jint value) {
    onPressLeft(value);
}

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    pressRight
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pressRight
        (JNIEnv *, jobject, jint value) {
    onPressRight(value);
}

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    touchEvent
 * Signature: (FFI)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_touchEvent
        (JNIEnv *, jobject, jfloat x, jfloat y, jint action) {
    onTouchEvent(x, y, action);
}

JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_yaw
        (JNIEnv *, jobject, jint value) {
    yaw(value);
}
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pitch
        (JNIEnv *, jobject, jint value) {
    pitch(value);
}

JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_roll
        (JNIEnv *, jobject, jint value) {
    roll(value);
}

JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_scroll
        (JNIEnv *, jobject, jfloat value){
    scroll(value);
}

JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_reset
        (JNIEnv *, jobject){
    reset();
}

}