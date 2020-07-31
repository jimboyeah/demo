#include <cstdio>

class Base
{
public:
    typedef enum {
        ABOUT = 1,
        CHILD = 3,
        POPUP,
        OVERLAPPE
    } Style;
    Base(Style);
};

Base::Base(Base::Style style)
{
    printf("Base with style %d ...\n", style);
}

typedef enum __Style {Big, Small, Tiny } Style;

int main()
{
    printf("Style Small: %d\n", Small);
    printf("Enum POPUP: %d\n", Base::POPUP);

    Style v1 = Big;
    Base::Style v2 = Base::OVERLAPPE;
    printf("Variable v1[Style Big: %d\n", v1);
    printf("Variable v2[Base::OVERLAPPE]: %d\n", v2);
    Base b(Base::POPUP);

    // Style vr = 1; 
    // Style vr = Base::CHILD; 
    // error: cannot convert 'Base::<unnamed enum>' to 'Style' {aka '__Style'} in initialization

    return 0;
}
