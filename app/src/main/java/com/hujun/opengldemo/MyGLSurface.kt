package com.hujun.opengldemo

import android.content.Context
import android.opengl.GLSurfaceView
import android.util.AttributeSet
import com.hujun.opengldemo.render.MyRender

/**
 * Created by junhu on 2019-11-26
 */
class MyGLSurface(context: Context?, attrs: AttributeSet?) : GLSurfaceView(context, attrs) {
    init {
        setEGLContextClientVersion(2)
        setRenderer(MyRender(this))
        renderMode = RENDERMODE_WHEN_DIRTY
    }
}