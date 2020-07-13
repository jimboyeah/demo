#include <iostream>
#include <fstream>
using namespace std;

int main () {
    streampos size;
    char * memblock;

    ifstream file ("file-binary.cpp.exe", ios::in|ios::binary|ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        file.close();

        cout << "the entire file content is in memory: " << size;

        delete[] memblock;
    }
    else cout << "Unable to open file";
    return 0;
}
    // std::vector<char> buf(4); // char is trivally copyable
    // std::fread(&buf[0], sizeof buf[0], buf.size(), f);

    // // write buffer to file
    // if(std::FILE* f1 = std::fopen("file.bin", "wb")) {
    //     std::array<int, 3> v = {42, -1, 7}; // underlying storage of std::array is an array
    //     std::fwrite(v.data(), sizeof v[0], v.size(), f1);
    //     std::fclose(f1);
    // }
 
    // // read the same data and print it to the standard output
    // if(std::FILE *f2 = std::fopen("file.bin", "rb")) {
    //     std::vector<int> rbuf(10); // underlying storage of std::vector is also an array
    //     std::size_t sz = std::fread(&rbuf[0], sizeof rbuf[0], rbuf.size(), f2);
    //     std::fclose(f2);
    //     for(std::size_t n = 0; n < sz; ++n) {
    //         std::printf("%d\n", rbuf[n]);
    //     }
    // }
