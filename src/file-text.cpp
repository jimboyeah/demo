#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int write (string file) {
    try
    {
        fstream myfile (file, ios::app|ios::ate);
        // myfile.open (file, ios::app);
        myfile.exceptions(myfile.failbit);
        int size = myfile.tellg();
        myfile.seekg (0, ios::beg);
        myfile << "// write comments by myself\n";
        myfile.close();
        cerr << "done!" << endl;
        return size;
    } catch (exception const& ex) {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    } catch (const std::ios_base::failure& e) {
        std::cout << "Caught an ios_base::failure.\n"
                  << "Error code: " << e.code().value() 
                  << " (" << e.code().message() << ")\n"
                  << "Error category: " << e.code().category().name() << '\n';

    }
    return 0;
}

int read(string file)
{
    string line;
    ifstream myfile (file, ios::ate);
    int size = myfile.tellg();
    myfile.seekg (0, ios::beg);
    if (!myfile.is_open())
    {
        cout << "Unable to open file: " << file; 
        return 0;
    }
    while ( getline (myfile, line) )
    {
        cout << line << '\n';
    }
    myfile.close();
    return size;
}

int main()
{
    string file = "../src/file-text.cpp";
    cout << write(file) << endl;
    cout << read(file) << endl;
}