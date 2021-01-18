/* filename: test.x */

const ADD = 0;
const SUB = 1;
const MUL = 2;
const DIV = 3;

struct TEST
{
    int op; /* 0-ADD, 1-SUB, 2-MUL, 3-DIV */
    float arg1;
    float arg2;
    float result;
};

program TEST_PROG
{
    version TEST_VER
    {
        struct TEST TEST_PROC(struct TEST) = 1;
    } = 2;
} = 0x20000001;
