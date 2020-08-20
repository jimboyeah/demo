package com.coding;

public class HelloBean { 
    private String msg; 
    
    public void setMsg(String msg) { 
        this.msg = msg; 
    } 
    public String getMsg() { 
        return msg; 
    } 
    public void afterPropertiesSet() {
        msg = "向全世界问好！";
    }
}