//

//  GrowthPush.cpp
//  growthpush-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

# include "GrowthPush.h"

# include <string>
# include <jni.h>

# include "cocos2d.h"
# include "platform/android/jni/JniHelper.h"

# include "../../Growthbeat/GbJsonHelper.h"

USING_NS_CC;
USING_NS_GROWTHPUSH;

static const char *const JavaClassName = "com/growthpush/GrowthPushJNI";

static gpDidReceiveRemoteNotificationCallback s_callback = nullptr;
static std::function<void(std::string)> s_showmessage_selector = nullptr;

extern "C" {
    JNIEXPORT void JNICALL Java_com_growthpush_Cocos2dxBridge_didOpenRemoteNotification(JNIEnv *env, jobject thiz, jstring jJson) {

         if (s_callback != nullptr) {
             std::string json = JniHelper::jstring2string(jJson);
             auto jsonValue = growthbeat::GbJsonHelper::parseJson2Value(json.c_str());
             s_callback(jsonValue);
         }

    }

    JNIEXPORT void JNICALL Java_com_growthpush_GrowthPushJNI_showMessageHandler(JNIEnv *env, jobject thiz, jstring jUDID) {

        if(s_showmessage_selector != nullptr) {
            std::string udid = JniHelper::jstring2string(jUDID);
            (s_showmessage_selector)(udid);
        }
    }

}

GrowthPush::GrowthPush(void)
{}

void GrowthPush::initialize(const std::string& applicationId, const std::string& credentialId, GPEnvironment environment) {

    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "initialize", "(Ljava/lang/String;Ljava/lang/String;I)V")) {
        jstring jApplicationId = t.env->NewStringUTF(applicationId.c_str());
        jstring jCredentialId = t.env->NewStringUTF(credentialId.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jApplicationId, jCredentialId, (int) environment);
        t.env->DeleteLocalRef(jApplicationId);
        t.env->DeleteLocalRef(jCredentialId);
        t.env->DeleteLocalRef(t.classID);
    }

}

void GrowthPush::requestDeviceToken() {
    // Do nothing on Android
}

void GrowthPush::requestDeviceToken(const std::string& senderId) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "requestRegistrationId", "(Ljava/lang/String;)V")) {
        jstring jSenderId = t.env->NewStringUTF(senderId.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jSenderId);
        t.env->DeleteLocalRef(jSenderId);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::trackEvent(const std::string& name) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "trackEvent", "(Ljava/lang/String;)V")) {
        jstring jName = t.env->NewStringUTF(name.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::trackEvent(const std::string& name, const std::string& value) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "trackEvent", "(Ljava/lang/String;Ljava/lang/String;)V")) {
        jstring jName = t.env->NewStringUTF(name.c_str());
        jstring jValue = t.env->NewStringUTF(value.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName, jValue);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(jValue);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::trackEvent(const std::string& name, const std::string& value, const ShowMessageHandler&showMessageHandler) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "trackEventWithShowMessageHandler", "(Ljava/lang/String;Ljava/lang/String;)V")) {
        s_showmessage_selector = showMessageHandler;
        jstring jName = t.env->NewStringUTF(name.c_str());
        jstring jValue = t.env->NewStringUTF(value.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName, jValue);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(jValue);
        t.env->DeleteLocalRef(t.classID);
    }
}


void GrowthPush::setTag(const std::string& name) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setTag", "(Ljava/lang/String;)V")) {
        jstring jName = t.env->NewStringUTF(name.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::setTag(const std::string& name, const std::string& value) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setTag", "(Ljava/lang/String;Ljava/lang/String;)V")) {
        jstring jName = t.env->NewStringUTF(name.c_str());
        jstring jValue = t.env->NewStringUTF(value.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jName, jValue);
        t.env->DeleteLocalRef(jName);
        t.env->DeleteLocalRef(jValue);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::setDeviceTags(void) {
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "setDeviceTags", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void GrowthPush::clearBadge(void) {
    // Do nothing on Android
}

void GrowthPush::renderMessage(const std::string& uuid) {

    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, JavaClassName, "renderMessage", "(Ljava/lang/String;)V")) {
        jstring jUUID = t.env->NewStringUTF(uuid.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jUUID);
        t.env->DeleteLocalRef(jUUID);
        t.env->DeleteLocalRef(t.classID);
    }

}

void GrowthPush::setOpenNotificationCallback(const gpDidReceiveRemoteNotificationCallback &callback) {
    s_callback = callback;
}

#endif
