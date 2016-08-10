//
//  GrowthLinkInstance.cpp
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "GrowthLink.h"

NS_GROWTHLINK_BEGIN

GrowthLink* GrowthLink::instance = new GrowthLink();

GrowthLink::~GrowthLink() {
    instance = NULL;
}

GrowthLink* GrowthLink::getInstance() {
    return instance;
}

NS_GROWTHLINK_END
