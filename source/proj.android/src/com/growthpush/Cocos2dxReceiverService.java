package com.growthpush;

import com.growthpush.bridge.ExternalFrameworkReceiverService;

public class Cocos2dxReceiverService extends ExternalFrameworkReceiverService {

    private com.growthpush.Cocos2dxBridge bridge;

    public Cocos2dxReceiverService() {
        super();
        this.bridge = new com.growthpush.Cocos2dxBridge();
    }

}
