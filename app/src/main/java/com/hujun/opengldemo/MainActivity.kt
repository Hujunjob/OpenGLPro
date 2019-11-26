package com.hujun.opengldemo

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.hujun.opengldemo.jni.Jni

class MainActivity : AppCompatActivity() {
    companion object{
        private val TAG = this::class.java.name.replace("${'$'}Companion","").split(".").last()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var s = Jni.stringFromJNI()
        Log.d(TAG, "onCreate: $s")

        Jni.nativeSetAssetManager(assets)
    }

}
