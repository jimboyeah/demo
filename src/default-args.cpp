    #include <iostream>

    void hello(const char* msg = "???")
    {
        std::cout << msg << std::endl;
    }
    int main()
    {
        hello("Hello ");
        hello("World ");
        hello();
        std::cout << "DONE!" << std::endl;
    }

