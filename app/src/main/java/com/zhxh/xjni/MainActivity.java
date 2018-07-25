package com.zhxh.xjni;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = findViewById(R.id.sample_text);
        tv.append(JNICall.getSingleton().stringFromJNI());
        tv.append("\n");
        tv.append(JNICall.getSingleton().helloFromJNI());
        tv.append("\n");
        //tv.append(JNICall.getSingleton().showUseJava());
    }
}
