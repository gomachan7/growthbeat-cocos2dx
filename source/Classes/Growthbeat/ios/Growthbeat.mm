//
//  GrowthAnalytics.mm
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "Growthbeat.h"

#import "GrowthbeatCCInternal.h"

USING_NS_CC;

growthbeat::Growthbeat::Growthbeat() {};

void growthbeat::Growthbeat::initializeIntentHandlers(){
    [GrowthbeatCCInternal initializeIntentHandlers];
}
void growthbeat::Growthbeat::addNoopIntentHandler(){
    [GrowthbeatCCInternal addNoopIntentHandler];

}
void growthbeat::Growthbeat::addUrlIntentHandler(){
    [GrowthbeatCCInternal addUrlIntentHandler];

}
void growthbeat::Growthbeat::addCustomIntentHandler(const OnHandle& handle){

    __block auto intentOnHandle = handle;
    [GrowthbeatCCInternal addCustomIntentHandlerWithBlock:^BOOL (GBCustomIntent *customIntent){
        NSDictionary *dict = customIntent.extra;
        std::map<std::string,std::string> extraMap;
        for (NSString *key in [dict allKeys]) {
            NSString *value= [dict objectForKey:key];
            extraMap[[key UTF8String]] = [value UTF8String];
        }
        return intentOnHandle(extraMap);
    }];
}

void growthbeat::Growthbeat::setLoggerSilent(bool silent) {
    [GrowthbeatCCInternal setLoggerSilent:silent];
}

#endif
