//
// Created by zhxh on 2018/7/23.
//

#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_zhxh_xjni_SoManager_showUseJava(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "jniJava";
    return env->NewStringUTF(hello.c_str());
}

