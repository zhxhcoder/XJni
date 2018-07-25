#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring
JNICALL
Java_com_zhxh_xjni_JNICall_helloFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "jhi-hello helloFromJNI";
    return env->NewStringUTF(hello.c_str());
}
