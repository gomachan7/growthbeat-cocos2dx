//
//  GrowthbeatCCInternal.h
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//

#include "ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <Growthbeat/Growthbeat.h>

@interface GrowthbeatCCInternal : NSObject

/* Growthbeat SDK interface */
+ (void)initializeWithApplicationId:(NSString *)applicationId credentialId:(NSString *)credentialId;
+ (void)start;
+ (void)stop;
+ (void)setLoggerSilent(bool silent);

@end

#endif // if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
