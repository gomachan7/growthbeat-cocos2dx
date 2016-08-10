//
//  GrowthbeatCCInternal.m
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import "GrowthbeatCCInternal.h"

@implementation GrowthbeatCCInternal

+ (void)initializeIntentHandlers{
    [Growthbeat sharedInstance].intentHandlers = [NSMutableArray array];
}

+ (void)addNoopIntentHandler{
    NSMutableArray *mutableArray = [[Growthbeat sharedInstance].intentHandlers mutableCopy];
    [mutableArray addObject:[[GBNoopIntentHandler alloc] init]];
    [Growthbeat sharedInstance].intentHandlers = mutableArray;
}

+ (void)addUrlIntentHandler{
    NSMutableArray *mutableArray = [[Growthbeat sharedInstance].intentHandlers mutableCopy];
    [mutableArray addObject:[[GBUrlIntentHandler alloc] init]];
    [Growthbeat sharedInstance].intentHandlers = mutableArray;
}

+ (void)addCustomIntentHandlerWithBlock:(BOOL(^)(GBCustomIntent *customIntent))block{
    NSMutableArray *mutableArray = [[Growthbeat sharedInstance].intentHandlers mutableCopy];
    [mutableArray addObject:[[GBCustomIntentHandler alloc] initWithBlock:block]];
    [Growthbeat sharedInstance].intentHandlers = mutableArray;
}

+ (void)setLoggerSilent:(bool)silent {
  [[Growthbeat sharedInstance] setLoggerSilent:silent];
}

@end

#endif /* if CC_TARGET_PLATFORM == CC_PLATFORM_IOS */
