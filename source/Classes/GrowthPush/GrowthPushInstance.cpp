//
//  GrowthPushInstance.cpp
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "GrowthPush.h"

NS_GROWTHPUSH_BEGIN

GrowthPush* GrowthPush::instance = new GrowthPush();

GrowthPush::~GrowthPush() {
	instance = NULL;
}

GrowthPush* GrowthPush::getInstance() {
    return instance;
}

NS_GROWTHPUSH_END
