//
// Created by zhxh on 2018/7/23.
//
#include <jni.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <android/log.h>
#include <string.h>

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

/**
 得到压力值
 0~250之间
*/
int pressure = 20;

int getPressure() {
    int increase = rand() % 20;
    pressure += increase;
    return pressure;
}


extern "C" JNIEXPORT jint

JNICALL
/**
 * 从感应器中得到压力值
 */
Java_com_zhxh_xjni_JNICall_getPressure(JNIEnv *env, jobject instance) {
    int pressure = getPressure();
    return pressure;
}

/**
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char *_JString2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid,
                                                         strencode); // String .getByte("GB2312");
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}


extern "C" JNIEXPORT void

JNICALL
Java_com_zhxh_xjni_JNICall_uninstallListener(JNIEnv *env, jobject instance,
                                             jstring jstrpackName, jint sdkVersion) {
    //返回三个值，大于0，父进程的id,等于0就是子进程的id,负数就是出错了
    int code = fork();
    if (code == 0) {
        //判断软件是否被卸载
        LOGE("child==%d\n", code);
        int flag = 1;
        while (flag) {
            sleep(1);//1秒
            //FILE	*fopen(const char *, const char *);
            char *packName = _JString2CStr(env, jstrpackName);
            FILE *file = fopen(packName, "r");// /data/data/com.zhxh.xjni
            if (file == NULL) {
                //应用对应的包名文件夹不存在, 说明已经被卸载了
                LOGE("软件被卸载");
                execlp("am", "am", "start", "--user", "0", "-a", "android.intent.action.VIEW", "-d",
                       "https://www.baidu.com", (char *) NULL);
                flag = 0;//停止循环
            } else {
                LOGE("软件没卸载");
            }

        }


    } else if (code > 0) {
        //父进程
        LOGE("father==%d\n", code);
    } else {
        //出错了
        LOGE("error==%d\n", code);
    }
}