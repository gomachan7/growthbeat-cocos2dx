//
//  GPAppDelegateWrapper.h
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GPAppDelegateWrapperDelegate.h"

@interface GPAppDelegateWrapper : UIResponder <UIApplicationDelegate> {

    id <GPAppDelegateWrapperDelegate> delegate;

}

@property (nonatomic, assign) id <GPAppDelegateWrapperDelegate> delegate;

- (void)setOriginalAppDelegate:(UIResponder <UIApplicationDelegate> *)newOriginalAppDelegate;

@end
