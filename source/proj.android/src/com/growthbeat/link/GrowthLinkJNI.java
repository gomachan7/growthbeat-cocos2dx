package com.growthbeat.link;

import android.content.Context;
import android.net.Uri;

public class GrowthLinkJNI {

	private static Context context = null;
	private static CountDownLatch latch = new CountDownLatch(1);

	public static void setContext(Context context) {
		GrowthLinkJNI.context = context;
	}

	public static void initialize(String applicationId, String credentialId) {
		if (context == null)
			throw new IllegalStateException("Must be setContext.");
		GrowthLink.getInstance().initialize(GrowthLinkJNI.context, applicationId, credentialId);
		latch.countDown();
	}

	public static void handleOpenUrl(Uri uri) {
		new Thread(new Runnable() {
			@Override
			public void run() {

				try {
					latch.await();
				} catch (InterruptedException e) {
				}

				GrowthLink.getInstance().handleOpenUrl(uri);

			}
		}).start();
	}

}
