#include <iostream>

// Definition & implementation combined together
class Skeleton {
    Skeleton() { std::cout << "Skeleton run ......" << std::endl; }
    friend class Singleton;
};

// Definition part
class Singleton: virtual Skeleton {
public:
    static Singleton instance();
    static Singleton *_instance;
};

// Implementation part
Singleton *Singleton::_instance = NULL;
Singleton Singleton::instance(){
    if( _instance ) return *_instance;
    _instance = new Singleton();
    std::cout << "_instance @ " << _instance << std::endl;
    return *_instance;
}

class X: private Singleton { };
int main()
{
    Singleton s, y = Singleton::instance();
    // X x; // error: 'Skeleton::Skeleton()' is private
    return &s == &y? 1:0;
}
