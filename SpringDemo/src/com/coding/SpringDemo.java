package com.coding;

import java.util.Calendar;
import java.util.Locale;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SpringDemo {
	public static void main(String[] args) { 
		ConfigurableApplicationContext context = new ClassPathXmlApplicationContext("beans-config.xml");
		Object[] arguments = new Object[] { "Guest", Calendar.getInstance().getTime() };
		System.out.println(context.getMessage("userLogin", arguments, Locale.US));
		System.out.println(context.getMessage("userLogin", arguments, Locale.TAIWAN));
		System.out.println(context.getMessage("userLogin", arguments, Locale.SIMPLIFIED_CHINESE));
		context.start(); // cause ContextStartedEvent
		context.stop();  // cause ContextStoppedEvent
	}
}