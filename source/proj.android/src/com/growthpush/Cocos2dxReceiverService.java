package com.growthpush;

import com.growthpush.bridge.ExternalFrameworkReceiverService;

public class Cocos2dxReceiverService extends ExternalFrameworkReceiverService {

    public Cocos2dxReceiverService() {
        super();
        this.bridge = new com.growthpush.Cocos2dxBridge();
    }

}
