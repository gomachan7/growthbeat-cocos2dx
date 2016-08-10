//
//  GPEnvironment.h
//  growthpush-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#ifndef __GROWTHPUSHPLUGIN_GPENVIRONMENT_H__
#define __GROWTHPUSHPLUGIN_GPENVIRONMENT_H__

#include "GPMacros.h"

NS_GROWTHPUSH_BEGIN

typedef enum GPEnvironment {
    GPEnvironmentUnknown = 0,
    GPEnvironmentDevelopment = 1,
    GPEnvironmentProduction = 2,
} GPEnvironment;

NS_GROWTHPUSH_END

#endif // __GROWTHPUSHPLUGIN_GPENVIRONMENT_H__
