# Growthbeat SDK for Cocos2d-x

===================

![Growthbeat](https://growthbeat.com/) is growth hack platform for smart devices.

## Product requirements

iOS6 ~ 8.4.1.
Android 2.3 ~ 6.0.

Cocos SDK 3.0 above.

## Build sample project

```bash
git clone https://github.com/SIROK/growthbeat-cocos2dx.git
cd ./growthbeat-cocos2dx/ ; git submodule update --init --recursive
```

## Install

### iOS

[1] Copy frameworks.

1. Copy Classes/Growthbeat, Classes/GrowthPush and Classes/GrowthAnalytics to /path/to/your_project/Classes/ 
1. Copy Growthbeat.framework to /path/to/your_project/proj.ios/Frameworks/
1. Added Classes in folder and framework to Xcode project.
1. Add dependecy frameworks. Foundation.framework, Security.framework, SystemConfiguration.framework, AdSupport.framework, CFNetwork.framework and libiconv.2.4.0.dylib.

### Android

1. Copy growthbeat-android/growthbeat.jar file to /path/to/your_project/proj.android/libs/


[1] Edit AndroidManifest.xml.

 ** Add permission . **

```xml
...
<uses-permission android:name="android.permission.INTERNET"/>
...
```

 ** Add permission and application setting when it uses Growth Push. **

```xml
<uses-permission android:name="com.google.android.c2dm.permission.RECEIVE" />
<permission
        android:name="YOUR_APPLICATION_PACKAGE_NAME.permission.C2D_MESSAGE"
        android:protectionLevel="signature" />

<uses-permission android:name="YOUR_APPLICATION_PACKAGE_NAME.permission.C2D_MESSAGE" />

<!-- optional permission. When need to sound and vibrate, use rich push.
<uses-permission android:name="android.permission.VIBRATE" />
<uses-permission android:name="android.permission.WAKE_LOCK" />
<uses-permission android:name="android.permission.SYSTEM_ALERT_WINDOW" />
-->

<applicaton>
	<!-- Summary -->
	<activity
        android:name="com.growthpush.view.AlertActivity"
        android:configChanges="orientation|keyboardHidden"
        android:launchMode="singleInstance"
        android:theme="@android:style/Theme.Translucent" />
	<receiver
        android:name="com.growthpush.Cocos2dxBroadcastReceiver"
        android:permission="com.google.android.c2dm.permission.SEND" >
        <intent-filter>
            <action android:name="com.google.android.c2dm.intent.RECEIVE" />
            <action android:name="com.google.android.c2dm.intent.REGISTRATION" />
			<category android:name="YOUR_APPLICATION_PACKAGE_NAME" />
        </intent-filter>
    </receiver>

</applicaton>

```

 ** Add application setting when it uses Growth Message. **

```xml

<applicaton>
	<!-- Summary -->
	<activity
            android:name="com.growthbeat.message.view.MessageActivity"
            android:theme="@android:style/Theme.Translucent" />
</application>

```

 ** Add application setting where it uses Growth Link. **

```xml
<application>
	<!-- Summary -->
	<receiver
        android:name="com.growthbeat.link.InstallReferrerReceiver"
        android:enabled="true"
        android:exported="true" >
        <intent-filter>
            <action android:name="com.android.vending.INSTALL_REFERRER" />
        </intent-filter>
    </receiver> 
</application>
```

[2] Add SetContext of GrowthbeatJNI LAUNCHER on AppActivity

```cpp

public class AppActivity extends Cocos2dxActivity {
  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    GrowthbeatJNI.setContext(getApplicationContext());
    GrowthLinkJNI.setContext(getApplicationContext());
	GrowthLinkJNI.handleOpenUrl(getIntent().getData());
  }
}
```

[3] Edit Android.mk.

```bash
LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/Growthbeat/GrowthbeatInstance.cpp \
                   ../../Classes/Growthbeat/android/Growthbeat.cpp \
                   ../../Classes/GrowthPush/GrowthPushInstance.cpp \
                   ../../Classes/GrowthPush/android/GrowthPush.cpp \
                   ../../Classes/GrowthAnalytics/GrowthAnalyticsInstance.cpp \
                   ../../Classes/GrowthAnalytics/android/GrowthAnalytics.cpp \
                   ../../Classes/GrowthLink/GrowthLinkInstance.cpp \
                   ../../Classes/GrowthLink/android/GrowthLink.cpp \
                   ../../Classes/GrowthbeatCore/GrowthbeatCoreInstance.cpp \
                   ../../Classes/GrowthbeatCore/android/GrowthbeatCore.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../Classes/Growthbeat/ \
					$(LOCAL_PATH)/../../Classes/Growthbeat/android \
					$(LOCAL_PATH)/../../Classes/GrowthPush/ \
					$(LOCAL_PATH)/../../Classes/GrowthPush/android \
					$(LOCAL_PATH)/../../Classes/GrowthAnalytics/ \
					$(LOCAL_PATH)/../../Classes/GrowthAnalytics/android \
					$(LOCAL_PATH)/../../Classes/GrowthLink/ \
					$(LOCAL_PATH)/../../Classes/GrowthLink/android \
					$(LOCAL_PATH)/../../Classes/GrowthbeatCore/ \
                    $(LOCAL_PATH)/../../Classes/GrowthbeatCore/android \
```


## GrowthbeatCocos2dx how to use (AppDelegate.cpp)

[1] Add the following to AppDelegate.cpp

```cpp
#include "Growthbeat.h"
#include "GrowthPush.h"
#include "GrowthbeatCore.h"
#include "GrowthAnalytics.h"
#include "GrowthLink.h"
```

[2] Add the following below #USING_NS_CC;

```cpp
USING_NS_GROWTHBEAT;
USING_NS_GROWTHPUSH;
USING_NS_GROWTHBEATCORE;
USING_NS_GROWTHLINK;
USING_NS_GROWTHANALYTICS;

#ifdef COCOS2D_DEBUG
GPEnvironment kGPEnvironment = GPEnvironmentDevelopment;
#else
GPEnvironment kGPEnvironment = GPEnvironmentProduction;
#endif

```

[3] Add the following under bool AppDelegate::applicationDidFinishLaunching()

```cpp
    Growthbeat::getInstance()->initialize("YOUR_APP_ID", "YOUR_CREDENTIAL_ID");
    GrowthPush::getInstance()->requestDeviceToken("YOUR_SENDER_ID", kGPEnvironment);
    Growthbeat::getInstance()->start();
```

[4] Add the following under bool AppDelegate::applicationWillEnterForeground()

```cpp
    Growthbeat::getInstance()->start();
```

[5] Add the following under bool AppDelegate::applicationDidEnterBackground()

```cpp
    Growthbeat::getInstance()->stop();
```

[6] If any places where the billing occurs, please add the following.
(CATEGORY: item、 gacha、 continue or custom strings)

```cpp
GrowthAnalytics::GetInstance()->purchase(PRICE, "CATEGORY", "PRODUCT");
```

[7] Please set in a possible acquisition range user information.

```cpp
GrowthAnalytics::GetInstance()->setUserId("USER_ID");
GrowthAnalytics::GetInstance()->setAge(AGE);
GrowthAnalytics::GetInstance()->setGender(GENDER);
GrowthAnalytics::GetInstance()->setLevel(LEVEL);
```

[8] Use deeplinking, Please set above.

```cpp
GrowthLink::getInstance()->initialize("PIaD6TaVt7wvKwao", "FD2w93wXcWlb68ILOObsKz5P3af9oVMo");
```

