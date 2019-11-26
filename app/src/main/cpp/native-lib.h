
#include "../../../../../../Library/Android/sdk/ndk/20.1.5948944/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/jni.h"
#include "utils.h"

#include <android/log.h>

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

}