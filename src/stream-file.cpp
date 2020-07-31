#include <iostream>
#include <iomanip> //for std::setw, std::setfill...
#include <fstream>
#include <sstream>
#include <bitset>

using namespace std;

#include "bin.cpp"

int main()
{
    char *c_str_file = (char*)"./log.txt";
    //never use std::string but via std::string.c_str
    string cpp_str_file("./log.txt");
    c_str_file = (char *)cpp_str_file.c_str();

    //error: no matching function std::basic_ofstream<char, std::char_traits<char> >::basic_ofstream(std::string&)
    //ofstream ofs(cpp_str_file);
    //ofstream ofs(c_str_file);
    //ifstream ifs(c_str_file);

    // Binary mode
    ofstream ofs(c_str_file, std::ios::binary);
    ifstream ifs(c_str_file, std::ios::binary);

    // Another way to open file for in/out
    //ofstream ofs;
    //ofs.open(c_str_file);
    //ifstream ifs;
    //ifs.open(c_str_file);
    // A better way is write and read speparately.
    // Four stream state is fail(), eof(), bad(), good(). bad() may true if disk broke

    if(ofs){ // if file not exist or file can be read/write
        ofs << "Hello world!" << endl;
        ofs << std::hex << 24 << 32 << 48 << endl;
        ofs << std::dec << 24 << 32 << 48 << endl;
        ofs << std::oct << 24 << 32 << 48 << endl;

        //ofs << std::bin << 24 << 32 << 48 << endl; // where is bin number
        std::bitset<sizeof(char) * 8> binary_24(24);
        std::bitset<sizeof(int) * 8> binary_32(32);
        std::bitset<sizeof(long) * 8> binary_48(48);
        ofs << binary_24 << endl;
        ofs << binary_32 << endl;
        ofs << binary_48 << endl;

        // Another way using bin.cpp
        ofs << std::bin(48) << endl;
        ofs << std::bin(56) << endl;

        ofs << std::dec; // set default decimal
        ofs.close();
        cout << "Data has printed out to " << c_str_file << endl;
    }else{ // if file is readonly or hidden, ofs evaluate to false
        cout << "Failure open " << c_str_file << " to write, it is readonly or hidden." << endl;
    }

    if(ifs){
        string line;
        long tick(0), v1(0), v2(0), v3(0);
        while(!ifs.eof() && tick < 10){
            tick ++;
            //if(ifs.eof()) break;
            std::getline(ifs, line); // use static function to get a whole line each step
            ifs >> v1 >> v2 >> v3; // read numeric line by line
            //ifs.read(cs, 2);
            if(ifs.fail()){ // if current content is not norrect, ifs.fail() will set true.
                cout << "Failed to read numeric data." << endl;
                ifs.clear(); // reset file-stream state
                break; // passby data below
            }
            cout << "Line " << ":" << line ;
            cout << " Integer Value:" << v1 << " " << v2 << " " << v3 << endl;
        }
        ifs.close();
    }else{
        cout << "Failed to open " << c_str_file << endl;
    }

    // Stream with std::string include in <ostream>: istringstream, ostringstream, stringstream
    stringstream ss;
    int i = 256;
    ss << "Hello String Stream!" << endl;
    ss << i << " is 0x" << std::hex << i << endl;
    cout << ss.str() << endl;
    cout << noboolalpha // default bool value with number 0 and 1
        << "noboolalpha - default bool values: "
        << true << " " << false << endl
        << "boolalpha - alpha bool values: "
        << boolalpha
        << true << " " << false << endl;

    int tick = 0;
    //while ((ch = cin.get()) != EOF)
    while(true){
        int c = ss.get();
        tick ++;
        //cout << "|" << std::isprint(c) << endl; // isprint return integer if c printable other then 0
        if(ss.eof()) break; // if read an enf-of-file then break while loop
        cout << std::hex << std::setw(2) << setfill('0') << c << ' ';
    }
    return 0;
}

/*
============================================================
Table A.4. Single-Byte Low-Level IO Operations is.get(ch)
 Puts next byte from the istream is in character ch. Returns is.

os.put(ch)
 Puts character ch onto the ostream os. Returns os.

is.get()
 Returns next byte from is as an int.

is.putback(ch)
 Puts character ch back on is; returns is.

is.unget()
 Moves is back one byte; returns is.

is.peek()
 Returns the next byte as an int but doesn't remove it.


Putting Back onto an Input Stream
Sometimes we need to read a character in order to know that we aren't ready for it yet. In such cases, we'd like to put the character back onto the stream. The library gives us three ways to do so, each of which has subtle differences from the others:

peek returns a copy of the next character on the input stream but does not change the stream. The value returned by peek stays on the stream and will be the next one retrieved.

unget backs up the input stream so that whatever value was last returned is still on the stream. We can call unget even if we do not know what value was last taken from the stream.

putback is a more specialized version of unget: It returns the last value read from the stream but takes an argument that must be the same as the one that was last read. Few programs use putback because the simpler unget does the same job with fewer constraints.

In general, we are guaranteed to be able to put back at most one value before the next read. That is, we are not guaranteed to be able to call putback or unget successively without an intervening read operation.



============================================================
Multi-Byte Operations

The get and getline functions take the same parameters, and their actions are similar but not identical. In each case, sink is a char array into which the data are placed. The functions read until one of the following conditions occurs:

size - 1 characters are read
End-of-file is encountered
The delimiter character is encountered


is.get(sink, size, delim)
  Reads up to size bytes from is and stores them in the character array pointed to by sink. Reads until encountering the delim character or until it has read size bytes or encounters end-of-file. If the delim is present, it is left on the input stream and not read into sink.

is.getline(sink, size, delim)
  Same behavior as three-argument version of get but reads and discards delim.

is.read(sink, size)
  Reads up to size bytes into the character array sink. Returns is.

is.gcount()
 Returns number of bytes read from the stream is by last call to an unformatted read operation.

os.write(source, size)
  Writes size bytes from the character array source to os. Returns os.

is.ignore(size, delim)
  Reads and ignores at most size characters up to but not including delim. By default, size is 1 and delim is end-of-file.



============================================================
Random Access to a Stream

Table A.6. Seek and Tell Functions seekg
 Reposition the marker in an input stream

tellg
 Return the current position of the marker in an input stream

seekp
 Reposition the marker for an output stream

tellp
 Return the current position of the marker in an output stream

Logically enough, we can use only the g versions on an istream or its derived types ifstream, or istringstream, and we can use only the p versions on an ostream or its derived types ofstream, and ostringstream. An iostream, fstream, or stringstream can both read and write the associated stream; we can use either the g or p versions on objects of these types.


Plain iostreams Usually Do Not Allow Random Access
The seek and tell functions are defined for all the stream types. Whether they do anything useful depends on the kind of object to which the stream is bound. On most systems, the streams bound to cin, cout, cerr and clog do not support random accessafter all, what would it mean to jump ten places back when writing directly to cout? We can call the seek and tell functions, but these functions will fail at run time, leaving the stream in an invalid state.

 Because the istream and ostream types usually do not support random access, the remainder of this section should be considered as applicable to only the fstream and sstream types.


*/