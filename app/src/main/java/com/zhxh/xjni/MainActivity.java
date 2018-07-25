package com.zhxh.xjni;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        UIUtils.init(this);

        TextView sample_text = findViewById(R.id.sample_text);
        sample_text.append(JNICall.getSingleton().helloFromJNI());
        sample_text.append("\n");
        sample_text.append(JNICall.getSingleton().showUseJava());

        Button btnJniToast = findViewById(R.id.btnJniToast);
        btnJniToast.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                JNICall.getSingleton().callBackToast();

            }
        });

    }
}
