/**
 * @file g0001-diff-ccpp.cpp
 * @author Jenago (jimbowhy@foxmail.com)
 * @brief  Kernel Programming Tutorials - basic structure difference between C and C++
 * @version 0.1
 * @date Sat May 25 08:20:55 CST 2024
 * @ref https://en.cppreference.com/w/c/language/basic_concepts
 * @ref https://en.cppreference.com/w/cpp/language/basic_concepts
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
// #include <strstream> // deprecated
#include <sstream>      // formal string stream via std::string
#include <string>

#include <cstdio>       // C++ style for stdio.h


class App
{
private:
    /* data */
    std::string message;

public:
    App(/* args */);
    void run();
    ~App();
};

App::App(/* args */)
{
    std::cout << "App::App() - app is constructing ..." << std::endl;
    message = "Hello C++!";
}

void App::run()
{
    std::cout << message << std::endl;
}

App::~App()
{
    std::cout << "App::~App() - app is destorying..." << std::endl;
}


int main(int argc, char *argv[])
{
    printf("Hello C style code under C++ code file.\n");
    App *app = new App();
    app->run();
    // app will auto destory after this function
    // or explict to delete it
    delete app;
}