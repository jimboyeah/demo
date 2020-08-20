package com.coding;

import org.springframework.context.ApplicationEvent;
import org.springframework.context.ApplicationListener;
import org.springframework.context.event.ContextStartedEvent;
import org.springframework.context.event.ContextStoppedEvent;

public class HelloListener implements ApplicationListener {
	@Override
	public void onApplicationEvent(ApplicationEvent e) {
		if (e instanceof ContextStartedEvent){
			System.out.println("Spring Started!");
		}else if (e instanceof ContextStoppedEvent){
			System.out.println("Spring Stopped!");
		}else{
			System.out.println("Spring Event:"+e.getClass().toString());
		}
	}
}