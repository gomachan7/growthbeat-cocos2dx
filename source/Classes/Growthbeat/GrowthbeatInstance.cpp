//
//  GrowthbeatInstance.cpp
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "Growthbeat.h"

NS_GROWTHBEAT_BEGIN

Growthbeat* Growthbeat::instance = new Growthbeat();

Growthbeat::~Growthbeat() {
	instance = NULL;
}

Growthbeat* Growthbeat::getInstance() {
    return instance;
}

NS_GROWTHBEAT_END
