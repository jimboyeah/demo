package com.coding;

import java.util.Calendar;
import java.util.Locale;
import java.util.stream.*;
import java.io.*;
import org.springframework.beans.factory.xml.*;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

public class SpringDemo 
{
	public static void main(String[] args) 
    { 
		ConfigurableApplicationContext context = new ClassPathXmlApplicationContext("beans-config.xml");
		Object[] arguments = new Object[] { "Guest", Calendar.getInstance().getTime() };
		System.out.println(context.getMessage("userLogin", arguments, Locale.US));
		System.out.println(context.getMessage("userLogin", arguments, Locale.TAIWAN));
		System.out.println(context.getMessage("userLogin", arguments, Locale.SIMPLIFIED_CHINESE));
		context.start(); // cause ContextStartedEvent
		context.stop();  // cause ContextStoppedEvent

        // InputStream is = new FileInputStream("beans-config.xml");
        // XmlBeanFactory factory = new XmlBeanFactory(is);
        // HelloBean hw = (HelloBean) factory.getBean("HelloBean");

        ApplicationContext actx = new FileSystemXmlApplicationContext("beans-config.xml");
        HelloBean hw = (HelloBean) actx.getBean("HelloBean");

        System.out.println("Bean msg: " + hw.getMsg());
	}
}