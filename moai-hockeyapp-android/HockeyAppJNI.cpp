#include <moai-hockeyapp-android/HockeyAppJNI.h>
#include <stdio.h>
#include <google-breakpad/src/client/linux/handler/exception_handler.h>
#include <google-breakpad/src/client/linux/handler/minidump_descriptor.h>

static google_breakpad::ExceptionHandler* exceptionHandler;
bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                  void* context,
                  bool succeeded) {
  printf("Dump path: %s\n", descriptor.path());
  return succeeded;
}

void Crash() {
  volatile int* a = reinterpret_cast<volatile int*>(NULL);
  *a = 1;
}

extern "C" {

	JNIEXPORT void JNICALL Java_se_skyturns_HockeyAppHandler_nativeCrash(JNIEnv* env, jobject obj) {
	  Crash();
	}

	JNIEXPORT void JNICALL Java_se_skyturns_HockeyAppHandler_setUpNative(JNIEnv* env, jobject obj, jstring filepath) {
		const char *path = env->GetStringUTFChars(filepath, 0);
		google_breakpad::MinidumpDescriptor descriptor(path);
		exceptionHandler = new google_breakpad::ExceptionHandler(descriptor, NULL, DumpCallback, NULL, true, -1);
	}

}