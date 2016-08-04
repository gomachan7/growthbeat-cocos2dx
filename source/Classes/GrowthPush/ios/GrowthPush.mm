//

//  GrowthPush.mm
//
//  Created by TSURUDA Ryo on 2013/12/07.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "GrowthPush.h"

#include "../../Growthbeat/GbJsonHelper.h"
#import "GrowthPushCCInternal.h"

USING_NS_CC;

// Don't use USING_NS_GROWTHPUSH. Because, it's conflict between GPEnvironment(C++) and GPEnvironment(Objective-C).

int environmentFromCocos(growthpush::GPEnvironment environment);

growthpush::GrowthPush::GrowthPush(void)
{}

void growthpush::GrowthPush::initialize(const std::string& applicationId, const std::string& credentialId, growthpush::GPEnvironment environment) {
    [GrowthPushCCInternal initializeWithApplicationId:[NSString stringWithUTF8String:applicationId.c_str()] credentialId:[NSString stringWithUTF8String:credentialId.c_str()] environment:environment];
}

void growthpush::GrowthPush::initialize(const std::string& applicationId, const std::string& credentialId, growthpush::GPEnvironment environment, bool adInfoEnable) {
    [GrowthPushCCInternal initializeWithApplicationId:[NSString stringWithUTF8String:applicationId.c_str()] credentialId:[NSString stringWithUTF8String:credentialId.c_str()] environment:environment adInfoEnable:adInfoEnable];
}

void growthpush::GrowthPush::requestDeviceToken() {
    [GrowthPushCCInternal requestDeviceToken];
}

void growthpush::GrowthPush::requestDeviceToken(const std::string& senderId) {

    CC_UNUSED_PARAM(senderId);
    requestDeviceToken();

}

void growthpush::GrowthPush::trackEvent(const std::string& name) {
    [GrowthPushCCInternal trackEvent:[NSString stringWithUTF8String:name.c_str()]];
}

void growthpush::GrowthPush::trackEvent(const std::string& name, const std::string& value) {
    [GrowthPushCCInternal trackEvent:[NSString stringWithUTF8String:name.c_str()] value:[NSString stringWithUTF8String:value.c_str()]];
}

void growthpush::GrowthPush::trackEvent(const std::string& name, const std::string& value, const ShowMessageHandle& handle) {
    [GrowthPushCCInternal trackEvent:[NSString stringWithUTF8String:name.c_str()] value:[NSString stringWithUTF8String:value.c_str()] showMessageHandler:^(NSString *uuid) {
        std::string uuidStr = [uuid UTF8String];
        handle(uuidStr);
    }];
}

void growthpush::GrowthPush::setTag(const std::string& name) {
    [GrowthPushCCInternal setTag:[NSString stringWithUTF8String:name.c_str()]];
}

void growthpush::GrowthPush::setTag(const std::string& name, const std::string& value) {
    [GrowthPushCCInternal setTag:[NSString stringWithUTF8String:name.c_str()] value:[NSString stringWithUTF8String:value.c_str()]];
}

void growthpush::GrowthPush::setDeviceTags(void) {
    [GrowthPushCCInternal setDeviceTags];
}

void growthpush::GrowthPush::clearBadge(void) {
    [GrowthPushCCInternal clearBadge];
}

// FIXME: for C++11
// void growthpush::GrowthPush::setOpenNotificationCallback(const growthpush::gpDidReceiveRemoteNotificationCallback
// &callback)
void growthpush::GrowthPush::setOpenNotificationCallback(Application *target, growthpush::GPRemoteNotificationCallback selector) {

    CCAssert(target, "target should not be NULL");
    CCAssert(selector, "selector should not be NULL");

    [GrowthPushCCInternal setDidReceiveNotificationBlock:^(NSString *json) {
         cocos2d::Value jsonValue = growthbeat::GbJsonHelper::parseJson2Value([json UTF8String]);
         (target->*selector)(jsonValue);
     }];

}

#endif
