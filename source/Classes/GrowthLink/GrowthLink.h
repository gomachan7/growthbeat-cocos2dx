//
//  GrowthLink.h
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2016/08/10.
//  Copyright (c) 2016 SIROK, Inc. All rights reserved.
//

#ifndef GROWTHLINKPLUGIN_GROWTHLINK_H_
#define GROWTHLINKPLUGIN_GROWTHLINK_H_
#include "cocos2d.h"
#include "GLMacros.h"

NS_GROWTHLINK_BEGIN

class CC_DLL GrowthLink
{
public:

    GrowthLink();
    ~GrowthLink();
    static GrowthLink* getInstance();

    void initialize(const std::string& applicationId, const std::string& credentialId);
    void handleOpenUrl(const std::string& url);

private:
    static GrowthLink* instance;
};

NS_GROWTHLINK_END

#endif
