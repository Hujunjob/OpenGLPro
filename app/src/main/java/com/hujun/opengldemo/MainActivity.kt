package com.hujun.opengldemo

import android.annotation.TargetApi
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.hujun.opengldemo.jni.Jni

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
    }

    @TargetApi(Build.VERSION_CODES.M)
    fun checkPermissions() {
        if (checkSelfPermission(android.Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED){
            requestPermissions(arrayOf(android.Manifest.permission.READ_EXTERNAL_STORAGE),1)
        }
    }

}
