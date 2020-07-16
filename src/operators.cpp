#include <string>
#include <cstdarg>
#include <iostream>

using namespace std;

/*-------------------------------*/
// Header            
/*-------------------------------*/
class Base
{
public:
    const char * text = "Test content...";
    Base(const char *);
    void operator=(Base &b);
    const char & operator[](int) const;
    friend ostream & operator<<(basic_ostream<char> &out, Base & b);
    ostream & operator<<(basic_ostream<char> &out);
    operator const char *(); // 重载强制类型转换运算符
};


/*-------------------------------*/
// Implementation            
/*-------------------------------*/
Base::Base(const char * value)
{
    this->text = value;
}

void Base::operator=(Base &b)
{
    this->text = b.text;
}

Base::operator const char *()
{
    return this->text;
}

const char & Base::operator[](int index) const
{
    return this->text[index];
}

// The problem is that you define it inside the class, which
// a) means the second argument is implicit (this) and
// b) it will not do what you want it do, namely extend std::ostream.
ostream & Base::operator<<(basic_ostream<char> &out)
{
    return out << "Base.text = " << this->text;
}


ostream & operator<<(basic_ostream<char> &out, Base & b)
{
    return out << "Base.text = " << b.text;
}


int main(int argc, char *argv[])
{
    Base a{"Some text..."};
    Base b{"More text..."};
    b = a;
    std::cout << "after operator<< : " << a << std::endl;
    std::cout << "after operator = : " << b << std::endl;
    std::cout << "after operator[1]: " << b[1] << std::endl;
    a << std::cout << " <--- use operator << as member function" << endl;
    std::cout << "after typecast: " << (const char *)b << endl;
    std::cout << "another typecast: " << b.operator const char *() << endl;
}