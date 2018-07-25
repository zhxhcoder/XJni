package com.zhxh.xjni;

/**
 * Created by zhxh on 2018/7/23
 */
public class JNICall {

    private JNICall() {
    }

    private static volatile JNICall instance;

    public static JNICall getSingleton() {
        if (instance == null) {
            synchronized (JNICall.class) {
                if (instance == null) {
                    instance = new JNICall();
                }
            }
        }
        return instance;
    }

    static {
        System.loadLibrary("jnihello");
        System.loadLibrary("jnijava");
    }

    public native String helloFromJNI();

    public native String showUseJava();

    public native String callBackToast();

    public native String nativeJNIMethodWithLog();

    public native void uninstallListener(String packName, int sdkVersion);
    public native int getPressure();
}
