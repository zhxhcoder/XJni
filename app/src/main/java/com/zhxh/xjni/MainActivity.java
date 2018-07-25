package com.zhxh.xjni;

import android.os.Build;
import android.os.Bundle;
import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
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

        TextView native_log_text = findViewById(R.id.native_log_text);
        native_log_text.append(JNICall.getSingleton().nativeJNIMethodWithLog());


        LinearLayout bombLayout = findViewById(R.id.bombLayout);

        final BombView bombView = new BombView(this);

        new Thread() {
            @Override
            public void run() {
                super.run();
                while (true) {
                    SystemClock.sleep(500);
                    int pressure = Math.abs(JNICall.getSingleton().getPressure());//0~250
                    bombView.setPressure(pressure);

                    if (pressure > 220) {//如果压力大于220就要爆炸
                        break;
                    }
                }


            }
        }.start();

        bombLayout.addView(bombView);


        JNICall.getSingleton().uninstallListener("/data/data/com.zhxh.xjni", Build.VERSION.SDK_INT);


        Button btnJniToast = findViewById(R.id.btnJniToast);
        btnJniToast.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                JNICall.getSingleton().callBackToast();

            }
        });

    }
}
