#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_zhxh_xjni_SoManager_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from SoManager Native";
    return env->NewStringUTF(hello.c_str());
}
