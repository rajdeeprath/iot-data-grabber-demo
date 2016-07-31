package com.red5pro.demos.datagrabber;

import org.red5.logging.Red5LoggerFactory;
import org.red5.server.adapter.MultiThreadedApplicationAdapter;
import org.red5.server.api.scope.IScope;
import org.slf4j.Logger;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import com.google.gson.internal.LinkedTreeMap;

public class Application extends MultiThreadedApplicationAdapter 
{
	private static Logger logger = Red5LoggerFactory.getLogger(Application.class, "data-grabber");
	
	
	
	
	
	/**
	 * Receives json string from IOT client 
	 * @param data
	 * @return
	 */
	public String receiveSensorData(String data)
	{
		JsonParser parser = new JsonParser();
		JsonObject o = parser.parse(data).getAsJsonObject();		
		logger.info(o.toString());
		
		return "200";
	}
	
	
}
