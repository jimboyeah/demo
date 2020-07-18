#include <cstdio>

#define LITTLE_ENDIAN ((char)(0x30313233)) == '3'
#define BIG_ENDIAN ((char)(0x30313233)) == '0'


int main()
{
    printf("BOM: %s %s \n", BIG_ENDIAN? "BIG_ENDIAN":"", LITTLE_ENDIAN? "LITTLE_ENDIAN":"");
    return 0;
}
