const int * mallocA(){  ///const data,non-const pointer
    int *a = new int(2);
    return a;
}

int main()
{
    const int *a = mallocA();
    // int *b = mallocA();  //  error: invalid conversion from 'const int*' to 'int*'
    return 0;
}