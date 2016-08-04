//
//  Growthbeat.h
//  growthbeat-cocos2dx
//
//  Created by Shigeru Ogawa on 2015/09/03.
//  Copyright (c) 2015 SIROK Inc. All rights reserved.
//

#ifndef __GROWTHBEATPLUGIN_GROWTHBEAT_H__
#define __GROWTHBEATPLUGIN_GROWTHBEAT_H__

#include "cocos2d.h"
#include "GbMacros.h"

NS_GROWTHBEAT_BEGIN
typedef std::function<bool(std::map<std::string,std::string>)> OnHandle;

class CC_DLL Growthbeat
{
public:

	Growthbeat();
	~Growthbeat();
	static Growthbeat* getInstance();

    void initializeIntentHandlers();
    void addNoopIntentHandler();
    void addUrlIntentHandler();
    void addCustomIntentHandler(const OnHandle& handle);
	void setLoggerSilent(bool silent);

private:
    OnHandle _handle;
 	static Growthbeat* instance;
};

NS_GROWTHBEAT_END

#endif  // __GROWTHBEATPLUGIN_GROWTHBEAT_H__
