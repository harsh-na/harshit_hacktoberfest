package com.clevermustafa.flash_blink_app

import android.Manifest
import android.app.Activity
import android.content.Context
import android.content.pm.PackageManager
import android.hardware.camera2.CameraManager
import android.os.Build
import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.material.Button
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.core.app.ActivityCompat
import com.clevermustafa.flash_blink_app.ui.theme.Flash_blink_appTheme
import kotlinx.coroutines.*

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)


        setContent {
            Flash_blink_appTheme {
                // A surface container using the 'background' color from the theme
                Surface(color = MaterialTheme.colors.background) {
                    BlinkButton(this, this)
                }
            }
        }
        if (ActivityCompat.checkSelfPermission(
                this,
                Manifest.permission.CAMERA
            ) != PackageManager.PERMISSION_GRANTED
        ) {
            ActivityCompat.requestPermissions(this, arrayOf(Manifest.permission.CAMERA), 200)
        }
    }
}


@Composable
fun BlinkButton(
    context: Context,
    activity: Activity
) {
    Box(
        modifier = Modifier
            .fillMaxHeight()
            .fillMaxWidth()
    ) {
        Button(
            onClick =  {
                if (ActivityCompat.checkSelfPermission(
                        context,
                        Manifest.permission.CAMERA
                    ) != PackageManager.PERMISSION_GRANTED
                ) {
                    Toast.makeText(context, "Permission not granted", Toast.LENGTH_SHORT).show()

                } else {
                    var camera = context.getSystemService(Context.CAMERA_SERVICE) as CameraManager
                    if (context.packageManager.hasSystemFeature(PackageManager.FEATURE_CAMERA_FLASH)) {
                        var light = false
                        var s = "10101010101010"
                        for (i in s.indices) {
                            light = s[i] == '1'
                            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                                camera.setTorchMode(camera.cameraIdList[0], light)
                            }

                        }
                    }

                }
            },
            modifier = Modifier.align(Alignment.Center)
        ) {
            Text(text = "Start Blinking")
        }
    }



}