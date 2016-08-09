package com.growthbeat.intenthandler;

import com.growthbeat.Growthbeat;
import com.growthbeat.model.CustomIntent;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class IntentHandlerJNI {

    private static List<IntentHandler> intentHandlers;

    public static void initializeIntentHandlers() {
        intentHandlers = new ArrayList<IntentHandler>();
        Growthbeat.getInstance().setIntentHandlers(intentHandlers);
    }

    public static void addNoopIntentHandler() {
        if (intentHandlers == null)
            throw new IllegalStateException("not initialized.");
        intentHandlers.add(new NoopIntentHandler());
    }

    public static void addUrlIntentHandler() {
        if (intentHandlers == null || Growthbeat.getInstance().getContext() == null)
            throw new IllegalStateException("not initialized.");
        intentHandlers.add(new UrlIntentHandler(Growthbeat.getInstance().getContext()));
    }

    public static void addCustomIntentHandler() {
        if (intentHandlers == null)
            throw new IllegalStateException("not initialized.");

        intentHandlers.add(new IntentHandler() {
            public boolean handle(com.growthbeat.model.Intent intent) {
                if (intent.getType() != com.growthbeat.model.Intent.Type.custom)
                    return false;
                Map<String, String> extra = ((CustomIntent) intent).getExtra();
                JSONObject json = new JSONObject();
                for (Map.Entry<String, String> entry : extra.entrySet()) {
                    try {
                        json.put(entry.getKey(), entry.getValue());
                    } catch (JSONException e) {
                    }
                }
                onHandled(json.toString());
                return true;
            }
        });
    }

    static native void onHandled(String json);

}
