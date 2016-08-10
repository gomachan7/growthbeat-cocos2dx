//
//  GrowthbeatCCInternal.h
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <Growthbeat/Growthbeat.h>

@interface GrowthbeatCCInternal : NSObject

+ (void)initializeIntentHandlers;
+ (void)addNoopIntentHandler;
+ (void)addUrlIntentHandler;
+ (void)addCustomIntentHandlerWithBlock:(BOOL(^)(GBCustomIntent *customIntent))block;
+ (void)setLoggerSilent:(bool)silent;

@end

#endif // if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
