//
//  Growthbeat.cpp
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "Growthbeat.h"

#include <string>
#include <jni.h>

#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"
#include "../GbJsonHelper.h"

USING_NS_CC;
USING_NS_GROWTHBEAT;

static std::function<bool(std::map<std::string,std::string>)> s_selector = nullptr;
extern "C"
{
    JNIEXPORT void JNICALL Java_com_growthbeat_intenthandler_IntentHandlerJNI_onHandled(JNIEnv* env, jobject thiz, jstring jJson)
    {
        if (s_selector != nullptr) {
            std::string json = JniHelper::jstring2string(jJson);
            (s_selector)(growthbeat::GbJsonHelper::parseJson2Map(json.c_str()));
        }
    }
};

growthbeat::Growthbeat::Growthbeat() {};

void Growthbeat::initializeIntentHandlers(void){
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "com.growthbeat.intenthandler.IntentHandlerJNI", "initializeIntentHandlers", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void Growthbeat::addNoopIntentHandler(void){
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "com.growthbeat.intenthandler.IntentHandlerJNI", "addNoopIntentHandler", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void Growthbeat::addUrlIntentHandler(void){
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "com.growthbeat.intenthandler.IntentHandlerJNI", "addUrlIntentHandler", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void Growthbeat::addCustomIntentHandler(const OnHandle& handle){
    CCAssert(handle, "selector should not be NULL");
    s_selector = handle;

    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, "com.growthbeat.intenthandler.IntentHandlerJNI", "addCustomIntentHandler", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }

}


void Growthbeat::setLoggerSilent(bool silent) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "com/growthbeat/GrowthbeatJNI", "setLoggerSilent", "(Z)V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID, silent);
        t.env->DeleteLocalRef(t.classID);
    }
}

#endif
