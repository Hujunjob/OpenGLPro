package com.hujun.opengldemo.jni

import android.content.res.AssetManager

/**
 * Created by junhu on 2019-11-26
 */
object Jni {
    // Used to load the 'native-lib' library on application startup.
    init {
        System.loadLibrary("native-lib")
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun OnDrawFrame()

    external fun onSurfaceChanged(width: Int, height: Int)

    external fun onSurfaceCreated()

    external fun nativeSetAssetManager(assetManager: AssetManager)

    external fun pressUp(value: Int)
    external fun pressDown(value: Int)
    external fun pressLeft(value: Int)
    external fun pressRight(value: Int)
    external fun touchEvent(x:Float,y:Float,action:Int);
}