package com.growthbeat;

public class GrowthbeatJNI {

	public static void setLoggerSilent(boolean silent) {
		Growthbeat.getInstance().setLoggerSilent(silent);
	}

}
