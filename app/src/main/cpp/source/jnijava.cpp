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

