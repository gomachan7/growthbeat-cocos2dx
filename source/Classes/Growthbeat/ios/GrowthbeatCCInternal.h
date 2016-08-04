//
//  GrowthbeatCCInternal.h
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2015/09/07.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "ccConfig.h"
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
