//
// Created by zhxh on 2018/7/23.
//

#include <jni.h>
#include <string>
#include <android/log.h>
#define LOG_TAG "nativeCodeWithLog"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jstring

JNICALL
Java_com_zhxh_xjni_JNICall_showUseJava(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "jni-Java showUseJava";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jstring

JNICALL
Java_com_zhxh_xjni_JNICall_callBackToast(
        JNIEnv *env,
        jobject instance/* this */) {

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);

    jclass jcls = env->FindClass("com/zhxh/xjni/UIUtils");
    //2.得到方法
    //最后一个参数是方法签名
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmIDs = env->GetMethodID(jcls, "showJniToast", "()V");

    //3.实例化该类
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    //jobject  jobject1 = (*env)->AllocObject(env,jcls);

    //4.调用方法
    //void    (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    env->CallVoidMethod(instance, jmIDs);
    //成功调用了static void showJniToast(String s)
}

/**
 * jstring ：返回值
 * Java_全类名_方法名
 * JNIEnv* env:里面有很多方法
 * jobject jobj：谁调用了这个方法就是谁的实例
 * 当前就是JNI.thi
 */
extern "C" JNIEXPORT jstring

JNICALL
Java_com_zhxh_xjni_JNICall_nativeJNIMethodWithLog(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "I am From native code!";
    LOGE("\nc函数中打印Log.e\n");
    return env->NewStringUTF(hello.c_str());
}


