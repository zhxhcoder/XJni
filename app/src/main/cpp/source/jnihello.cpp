#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_zhxh_xjni_JNICall_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "stringFromJNI from JNICall Native";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring
JNICALL
Java_com_zhxh_xjni_JNICall_helloFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "helloFromJNI from JNICall Native";
    return env->NewStringUTF(hello.c_str());
}
