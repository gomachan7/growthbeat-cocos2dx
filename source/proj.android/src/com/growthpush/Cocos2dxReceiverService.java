package com.growthpush;

import com.growthpush.bridge.ExternalFrameworkReceiverService;

public class Cocos2dxReceiverService extends ExternalFrameworkReceiverService {

	private Cocos2dxBridge bridge;

	public Cocos2dxReceiverService() {
		super();
		this.bridge = new Cocos2dxBridge();
	}

}
