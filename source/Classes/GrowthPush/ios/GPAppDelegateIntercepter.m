//
//  GPAppDelegateIntercepter.m
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import "GPAppDelegateIntercepter.h"

#import "GrowthPushCCInternal.h"

@implementation GPAppDelegateIntercepter

- (BOOL) didPerformApplication:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    return [GrowthPushCCInternal application:application didFinishLaunchingWithOptions:launchOptions];
}

- (void) didPerformApplication:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    [GrowthPushCCInternal application:application didReceiveRemoteNotification:userInfo];
}

- (void) willPerformApplication:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [GrowthPushCCInternal application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}

- (void) willPerformApplication:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    [GrowthPushCCInternal application:application didFailToRegisterForRemoteNotificationsWithError:error];
}


@end

#endif /* if CC_TARGET_PLATFORM == CC_PLATFORM_IOS */
