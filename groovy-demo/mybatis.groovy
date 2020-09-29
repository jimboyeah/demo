/*
SpringBoot Groovy 脚本项目执行：
{
    "name": "🤍 Spring CLI Watch Groovy",
    "shell_cmd": "cd ${file_path} && spring run --watch ${file_name}"
},
*/

// package com.demos.mybatis;

@Grab(group='org.mybatis.spring.boot', module='mybatis-spring-boot-starter', version='2.1.3')

@Grab(group='mysql', module='mysql-connector-java', version='8.0.21')

@Grab(group='com.fasterxml.jackson.core', module='jackson-annotations', version='2.9.9')

// https://mvnrepository.com/artifact/org.springframework.boot/spring-boot-starter
@Grapes(
    @Grab(group='org.springframework.boot', module='spring-boot-starter', version='2.3.3.RELEASE')
)
// https://mvnrepository.com/artifact/org.springframework.boot/spring-boot-starter-web
@Grapes(
    @Grab(group='org.springframework.boot', module='spring-boot-starter-web', version='2.3.3.RELEASE')
)


import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonIgnore;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Result;
import org.apache.ibatis.annotations.Results;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;


// ==========================================================
//  @SpringApplication 默认由 Groovy 提供
// ==========================================================

@SpringBootApplication
// @MapperScan("com.demos.mybatis")
public class MybatisAnnotationApplication 
{
    public static void main(String[] args) 
    {
        SpringApplication.run(MybatisAnnotationApplication.class, args);
        print("Run com.demos.mybatis...");
    }
}

// ==========================================================
//  @Controller
// ==========================================================

@RestController
public class UserController {
    
    @Autowired
    private UserMapper userMapper;
    
    @RequestMapping("/getUsers")
    public List<User> getUsers() {
        List<User> users=userMapper.getAll();
        return users;
    }
    
    @RequestMapping("/getUser")
    public User getUser(Long id) {
        User user=userMapper.getOne(id);
        return user;
    }
    
    @RequestMapping("/add")
    public void save(User user) {
        userMapper.insert(user);
    }
    
    @RequestMapping(value="update")
    public void update(User user) {
        userMapper.update(user);
    }
    
    @RequestMapping(value="/delete/{id}")
    public void delete(@PathVariable("id") Long id) {
        userMapper.delete(id);
    }
}

// ==========================================================
//  @Model
// ==========================================================
import java.io.Serializable;

public enum UserSexEnum {
    MAN, WOMAN
}

public class User implements Serializable 
{
    // Groovy auto make utils getter/setter method for public member 
    public static final long serialVersionUID = 1L;
    public Long id;
    public String userName;
    public String passWord;
    public UserSexEnum userSex;
    public String nickName;

    @JsonFormat(pattern = "yyyy-MM-dd")
    public Date date = new Date();

    public User() 
    {
        super();
    }

    public User(String userName, String passWord, UserSexEnum userSex) 
    {
        super();
        this.passWord = passWord;
        this.userName = userName;
        this.userSex = userSex;
    }

    @Override
    public String toString() 
    {
        // TODO Auto-generated method stub
        return "userName " + this.userName + ", pasword " + this.passWord + "sex " + userSex.name();
    }
}

// ==========================================================
//  @MapperInterface
// ==========================================================
// modify @Results({....}) -> @Results([....])
// Groovy closure use {}, array use []
// or you will got compilation error: Unexpected token @

public interface UserMapper 
{
    @Select("SELECT * FROM users")
    @Results([
        @Result(property = "userSex",  column = "user_sex", javaType = UserSexEnum.class),
        @Result(property = "nickName", column = "nick_name")
    ])
    List<User> getAll();
    
    @Select("SELECT * FROM users WHERE id = #{id}")
    @Results([
        @Result(property = "userSex",  column = "user_sex", javaType = UserSexEnum.class),
        @Result(property = "nickName", column = "nick_name")
    ])
    User getOne(Long id);

    @Insert("INSERT INTO users(userName,passWord,user_sex) VALUES(#{userName}, #{passWord}, #{userSex})")
    void insert(User user);

    @Update("UPDATE users SET userName=#{userName},nick_name=#{nickName} WHERE id =#{id}")
    void update(User user);

    @Delete("DELETE FROM users WHERE id =#{id}")
    void delete(Long id);
}
