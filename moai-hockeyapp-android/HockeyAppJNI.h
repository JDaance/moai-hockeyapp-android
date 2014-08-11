#ifndef HOCKEYAPP_JNI_H
#define HOCKEYAPP_JNI_H

#include <jni.h>

extern "C" {
	JNIEXPORT void JNICALL Java_se_skyturns_HockeyAppHandler_setUpNative(JNIEnv* env, jobject obj, jstring filepath);
}

#endif
