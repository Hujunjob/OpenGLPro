package com.hujun.opengldemo

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import com.hujun.opengldemo.jni.Jni
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {
    companion object{
        private val TAG = this::class.java.name.replace("${'$'}Companion","").split(".").last()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var s = Jni.stringFromJNI()
        Log.d(TAG, "onCreate: $s")
    }

}
