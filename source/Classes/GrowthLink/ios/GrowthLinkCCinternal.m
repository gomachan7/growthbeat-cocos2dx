//
//  GrowthLinkCCInternal.m
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//


#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import "GrowthLinkCCInternal.h"

@implementation GrowthLinkCCInternal


+ (void)initializeWithApplicationId:(NSString *)applicationId credentialId:(NSString *)credentialId{
    [[GrowthLink sharedInstance] initializeWithApplicationId:applicationId credentialId:credentialId];
}

+ (void) handleOpenUrl:(NSString *)urlString{
    [[GrowthLink sharedInstance] handleOpenUrl:[NSURL URLWithString:urlString]];
}

@end

#endif /* if CC_TARGET_PLATFORM == CC_PLATFORM_IOS */
