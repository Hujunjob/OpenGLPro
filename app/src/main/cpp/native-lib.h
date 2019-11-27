
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

JNIEXPORT void JNICALL Java_com_hujun_opengldemo_jni_Jni_nativeSetAssetManager
        (JNIEnv *, jobject,jobject);

}