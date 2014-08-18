// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include <moai-hockeyapp-android/host.h>
#include <moai-hockeyapp-android/HockeyAppJNI.h>

//================================================================//
// aku
//================================================================//

//----------------------------------------------------------------//
void MOAIHockeyAppAndroidAppFinalize () {
}

//----------------------------------------------------------------//
static bool hockeyImpossibleCondition = rand() < 0;
void MOAIHockeyAppAndroidAppInitialize () {
	// trick compiler/linker to include function
	if (hockeyImpossibleCondition) {
		Java_se_skyturns_HockeyAppHandler_setUpNative(NULL, NULL, NULL);
	}
}

//----------------------------------------------------------------//
void MOAIHockeyAppAndroidContextInitialize () {
}