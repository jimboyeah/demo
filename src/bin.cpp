/*
 * A way to provide inline std::bin() act somehow like std::hex, std::oct ...
 * http://bytes.com/topic/c/answers/496452-std-binary-n
 * Here's something I put together just now; whilst I don't know enough
 * to make this act the same way std::hex and std::dec does, this works
 * quite well enough for me, but I think I could improve on this.
 * Suggestions and flames both welcome. To use, try this:
 *  unsigned char ch = 0x80;
 *  std::cout << std::binary(ch) << "\n";
 * ex src\stream-file.cpp
 */
#include <iostream>

using namespace std;

namespace std
{
    template <typename T>
    struct binary
    {
        std::string digits;
    };

    template <typename T>
    inline binary<T> bin(T v)
    {
        binary<T> _bin;
        int bits = sizeof(v);

        switch (bits)
        {
            case 1: bits = 7; break;
            case 2: bits = 15; break;
            case 4: bits = 31; break;
            // add more if necessary
        }

        for (int i=bits; i>=0; i--)
        {
            char *pad = (char *)((v>>i)&1? "1":"0");
            _bin.digits.append(pad);
        }

        return _bin;
    }

    // overload operator << to provide code inline
    template <typename T>
    ostream& operator << (ostream& stream, binary<T> _bin)
    {
        stream << _bin.digits;
        return stream;
    }
}

