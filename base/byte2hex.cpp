#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

#define byte unsigned char

const char *byte2hex(byte bytes[]){
    stringstream ss;
    ss << std::hex;
    int len = string((char*)bytes).length(); // 9 OK, count for characters
    // cout << "sizeof bytes:" << sizeof(bytes) << endl; // Failed, Precompiler determine array pointer size
    for(int i=0; i<len; i++){
        int j = (int)bytes[i];
        ss << " 0x" << (j<16?"0":"") << j;
    }

    string so = ss.str();
    //string *ps = new string(so.length()+1,0); // allocate memory return to caller
    //ps->assign( so );
    //const char *p = ps->c_str();
    string *s = new string(so);
    const char *p = s->c_str();
    return p;
}

int main(){
    byte a[] = "\x1\x2\x3\x41\xd\abcd"; // C-style with NULL
    byte *pa = a;
    cout << "sizeof a:" << sizeof(a) << endl;   // OK, Precompiler determine array size
    cout << "sizeof pa:" << sizeof(pa) << endl; // OK, Precompiler determine pointer size
    const char * s = byte2hex(a);
    cout << "\nFinal:" << s << endl;
    delete s;
    return 0;
}