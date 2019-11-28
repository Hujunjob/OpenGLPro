package com.hujun.opengldemo

import android.annotation.TargetApi
import android.app.ActivityManager
import android.content.Context
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.util.Log
import android.view.MotionEvent
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import com.hujun.opengldemo.jni.Jni
import kotlinx.android.synthetic.main.activity_main.*


class MainActivity : AppCompatActivity() {
    companion object {
        private val TAG = this::class.java.name.replace("${'$'}Companion", "").split(".").last()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var s = Jni.stringFromJNI()
        Log.d(TAG, "onCreate: $s")

        Jni.nativeSetAssetManager(assets)
        checkPermissions()

        val am = getSystemService(Context.ACTIVITY_SERVICE) as ActivityManager
        val info = am.deviceConfigurationInfo
        Log.d(TAG, "onCreate: glEsVersion = ${info.glEsVersion}")

        btn_up.setOnClickListener { Jni.pressUp(1) }
        btn_down.setOnClickListener { Jni.pressDown(1) }
        btn_left.setOnClickListener { Jni.pressLeft(1) }
        btn_right.setOnClickListener { Jni.pressRight(1) }

        btn_yaw.setOnClickListener { Jni.yaw(1) }
        btn_pitch.setOnClickListener { Jni.pitch(1) }
        btn_roll.setOnClickListener { Jni.roll(1) }

        btn_zoomin.setOnClickListener { Jni.scroll(-5.0f) }
        btn_zoomout.setOnClickListener { Jni.scroll(5.0f) }
        btn_reset.setOnClickListener { Jni.reset() }

        btn_up.setOnHoverListener { _, _ ->
            Jni.pressUp(1)
            true
        }
    }

    @TargetApi(Build.VERSION_CODES.M)
    fun checkPermissions() {
        if (checkSelfPermission(android.Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            requestPermissions(arrayOf(android.Manifest.permission.READ_EXTERNAL_STORAGE), 1)
        }
    }

}
