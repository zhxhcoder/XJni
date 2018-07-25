package com.zhxh.xjni;

import android.content.Context;
import android.widget.Toast;

/**
 * Created by zhxh on 2018/7/25
 */
public class UIUtils {

    private static Context ctx;

    public static void init(Context ctx) {
        UIUtils.ctx = ctx;
    }

    public void showToast(String text) {
        Toast.makeText(ctx, text, Toast.LENGTH_SHORT).show();
    }

    public void showJniToast() {
        showToast("这是jni调用的java代码中的toast");
    }

}
