//
//  GrowthLinkCCInternal.h
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <Growthbeat/Growthbeat.h>

@interface GrowthLinkCCInternal : NSObject

+ (void)initializeWithApplicationId:(NSString *)applicationId credentialId:(NSString *)credentialId;

+ (void) handleOpenUrl:(NSString *)urlString;

@end

#endif
