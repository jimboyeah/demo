using namespace System;
using namespace System::Web;
using namespace System::ComponentModel;

#using <System.DLL>
// #using <System.Web>
// #using <System.ComponentModel.DLL> 

class HelloWorld
{
public:
    static void Main()
    {
#if DebugConfig
        Console::WriteLine("WE ARE IN THE DEBUG CONFIGURATION");
#endif
        Console::WriteLine("HELLO, WORLD!");
    }
};

int main()
{
    HelloWorld::Main();
    // System::ComponentModel::Container ^components;
    IHttpModule ihm;
    return 0;
}