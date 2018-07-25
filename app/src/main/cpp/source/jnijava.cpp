//
// Created by zhxh on 2018/7/23.
//

#include <jni.h>
#include <string>

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

    jclass jcls= env->FindClass("com/zhxh/xjni/UIUtils");
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

