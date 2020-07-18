#include <cstdio>
#include <typeinfo>

class Base
{
    class _neasted
    {
        const char *data = "some secret";
    public:
        void test()
        { 
            printf("%s\n", typeid(*this).name()); 
        };
    };

public:
    Base()
    {
        _neasted _n;
        neasted n;
        printf("Construct %s\n", typeid(*this).name());
        // error: 'char Base::_neasted::data []' is private within this context
        // printf("--> Test _neasted: %s\n", _n.data);
        printf("--> Test neasted: %s\n", n.data);
    }

    ~Base()
    {
        printf("Destructure of %s\n", __FUNCTION__);
    }
    
    class neasted
    {
    public:
        const char *data = "some string";
        void test()
        { 
            printf("%s\n", typeid(*this).name()); 
        }
    };
};


int main()
{
    Base();

    // error: 'class Base::_neasted' is private within this context
    // Base::_neasted _n;
    Base::neasted n;
    printf("%s:\n", __FUNCTION__);
    printf("--> Test neasted: %s\n", n.data);

    return 0;
}
