//
//  GrowthLink.mm
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#include "base/ccConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS


#include "GrowthLink.h"
#include "GrowthLinkCCInternal.h"

USING_NS_CC;
USING_NS_GROWTHLINK;

growthlink::GrowthLink::GrowthLink() {};

void growthlink::GrowthLink::initialize(const std::string& applicationId, const std::string& credentialId) {
    [GrowthLinkCCInternal initializeWithApplicationId:[NSString stringWithUTF8String:applicationId.c_str()] credentialId:[NSString stringWithUTF8String:credentialId.c_str()]];
}

void growthlink::GrowthLink::handleOpenUrl(const std::string& url){
    [GrowthLinkCCInternal handleOpenUrl:[NSString stringWithUTF8String:url.c_str()]];
}

#endif
