package com.hujun.opengldemo.render

import android.opengl.GLSurfaceView
import com.hujun.opengldemo.MyGLSurface
import com.hujun.opengldemo.jni.Jni
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class MyRender(var myGLSurface: MyGLSurface) : GLSurfaceView.Renderer {
    companion object{
        private val TAG = this::class.java.name.replace("${'$'}Companion","").split(".").last()
    }
    override fun onDrawFrame(p0: GL10?) {
//        Log.d(TAG, "onDrawFrame: ")
        Jni.OnDrawFrame()
//        myGLSurface.requestRender()
    }

    override fun onSurfaceChanged(p0: GL10?, width: Int, height: Int) {
//        Log.d(TAG, "onSurfaceChanged: ")
        Jni.onSurfaceChanged(width,height)
    }

    override fun onSurfaceCreated(p0: GL10?, p1: EGLConfig?) {
//        Log.d(TAG, "onSurfaceCreated: ")
        Jni.onSurfaceCreated()
    }

}
