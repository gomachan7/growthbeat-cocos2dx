package com.growthpush;

import java.util.HashMap;
import java.util.UUID;

import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.content.Context;

import com.growthbeat.message.handler.ShowMessageHandler;
import com.growthbeat.message.handler.ShowMessageHandler.MessageRenderHandler;
import com.growthpush.model.Environment;

public class GrowthPushJNI {

	private static Context context;
	private static HashMap<String, MessageRenderHandler> renderHandlers = new HashMap<String, ShowMessageHandler.MessageRenderHandler>();

	public static void setContext(Context context) {
		GrowthPushJNI.context = context;
	}

	public static void initialize(String applicationId, String credentialId, final int environment) {
		if (context == null)
			throw new IllegalStateException("Must be setContext.");

		GrowthPush.getInstance().initialize(context, applicationId, credentialId, convertIntToEnvironment(environment));
	}

	public static void requestRegistrationId(final String senderId) {
		GrowthPush.getInstance().requestRegistrationId(senderId);
	}

	public static void trackEvent(final String name) {
		trackEvent(name, null);
	}

	public static void trackEvent(final String name, final String value) {
		GrowthPush.getInstance().trackEvent(name, value);
	}

	public static void trackEventWithShowMessageHandler(final String name, final String value) {
		GrowthPush.getInstance().trackEvent(name, value, new ShowMessageHandler() {

			@Override
			public void error(String error) {
			}

			@Override
			public void complete(final MessageRenderHandler messageRenderHandler) {

				Cocos2dxGLSurfaceView.getInstance().queueEvent(new Runnable() {
					@Override
					public void run() {
						String uuid = UUID.randomUUID().toString();
						renderHandlers.put(uuid, messageRenderHandler);
						showMessageHandler(uuid);
					}
				});

			}
		});
	}

	public static void setTag(final String name) {
		setTag(name, null);
	}

	public static void setTag(final String name, final String value) {
		GrowthPush.getInstance().setTag(name, value);
	}

	public static void setDeviceTags() {
		GrowthPush.getInstance().setDeviceTags();
	}

	public static Environment convertIntToEnvironment(int environment) {

		switch (environment) {
		case 1:
			return Environment.development;
		case 2:
			return Environment.production;
		default:
			return null;
		}

	}

	public static void renderMessage(String uuid) {
		if (renderHandlers.containsKey(uuid)) {
			renderHandlers.get(uuid).render();
			renderHandlers.remove(uuid);
		}
	}

	/*
	 * callback message uudi
	 * 
	 * @param uuid
	 */
	static native void showMessageHandler(String uuid);

}
