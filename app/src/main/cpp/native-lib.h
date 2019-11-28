
#include "utils/utils.h"

#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

extern "C" {

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_hujun_opengldemo_jni_Jni_stringFromJNI
        (JNIEnv *, jobject);

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    OnDrawFrame
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_OnDrawFrame
        (JNIEnv *, jobject);

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    onSurfaceChanged
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_onSurfaceChanged
        (JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    onSurfaceCreated
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_onSurfaceCreated
        (JNIEnv *, jobject);

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    nativeSetAssetManager
 * Signature: (Landroid/content/res/AssetManager;)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_nativeSetAssetManager
        (JNIEnv *, jobject, jobject);

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    pressUp
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pressUp
        (JNIEnv *, jobject, jint);

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    pressDown
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pressDown
        (JNIEnv *, jobject, jint);

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    pressLeft
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pressLeft
        (JNIEnv *, jobject, jint);

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    pressRight
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pressRight
        (JNIEnv *, jobject, jint);

/*
 * Class:     com_hujun_opengldemo_jni_Jni
 * Method:    touchEvent
 * Signature: (FFI)V
 */
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_touchEvent
        (JNIEnv *, jobject, jfloat, jfloat, jint);

JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_yaw
        (JNIEnv *, jobject, jint);
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_pitch
        (JNIEnv *, jobject, jint);
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_roll
        (JNIEnv *, jobject, jint);
JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_scroll
        (JNIEnv *, jobject, jfloat);
}