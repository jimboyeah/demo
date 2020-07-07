    #include <iostream>
    #include <thread>
    #include <chrono>

    void hello(int delay, const char* msg)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        std::cout << msg;
    }
    int main()
    {
        std::thread t1(hello, 200, "Hello ");
        std::thread t2(hello, 200, "Concurrent ");
        std::thread t3(hello, 200, "World ");
        t1.join();
        t2.join();
        t3.join();
        std::cout << "DONE!" << std::endl;
    }

