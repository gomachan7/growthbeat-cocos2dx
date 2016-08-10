//
//  GrowthLinkPlugin.m
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//
#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "GrowthLinkPlugin.h"
#import <Growthbeat/GrowthLink.h>
#import <objc/runtime.h>

@implementation UIApplication (GrowthLinkPlugin)

+(void)load
{
    method_exchangeImplementations(class_getInstanceMethod(self, @selector(setDelegate:)), class_getInstanceMethod(self, @selector(setGrowthLinkDelegate:)));

}

BOOL GLOpenURL(id self, SEL _cmd, id application, id url, id sourceApplication, id annotation) {
if ([self respondsToSelector:@selector(application:linkOpenURL:sourceApplication:annotation:)])
    {
        [self application:application linkOpenURL:url sourceApplication:sourceApplication annotation:annotation];
    }

    if ([GrowthLink instancesRespondToSelector:@selector(handleOpenUrl:)])
    {
        [[GrowthLink sharedInstance] handleOpenUrl: url];
    }

    return YES;

}

- (void) setGrowthLinkDelegate:(id<UIApplicationDelegate>)delegate
{
    static Class delegateClass = nil;
    if(delegateClass == [delegate class])
    {
        [self setGrowthLinkDelegate:delegate];
        return;
    }

    delegateClass = [delegate class];
    exchangeMethodImplementations(delegateClass, @selector(application:openURL:sourceApplication:annotation:),
                                  @selector(application:linkURL:sourceApplication:annotation:), (IMP)GLOpenURL, "v@:::");
    [self setGrowthLinkDelegate:delegate];
}

static void exchangeMethodImplementations(Class class, SEL oldMethod, SEL newMethod, IMP impl, const char * signature)
{
    Method method = nil;
    method = class_getInstanceMethod(class, oldMethod);

    if (method)
    {
        class_addMethod(class, newMethod, impl, signature);
        method_exchangeImplementations(class_getInstanceMethod(class, oldMethod), class_getInstanceMethod(class, newMethod));
    }
    else
    {
        class_addMethod(class, oldMethod, impl, signature);
    }
}


@end

#endif
