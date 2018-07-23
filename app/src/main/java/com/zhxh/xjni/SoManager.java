package com.zhxh.xjni;

/**
 * Created by zhxh on 2018/7/23
 */
public class SoManager {

    private SoManager() {
    }

    private static volatile SoManager instance;

    public static SoManager getSingleton() {
        if (instance == null) {
            synchronized (SoManager.class) {
                if (instance == null) {
                    instance = new SoManager();
                }
            }
        }
        return instance;
    }

    static {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI();

}
