#include <iostream>
#include <fstream>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1

int main( int argc, char* argv[] )
{
    // output file name (argv[0])
    std::cout << "program: " << argv[0] << '\n';
    
    // open file CString(argv[arg]), count lines, output lines, close file. loop
    for (int arg = 1; arg < argc; ++arg)
    {
        int count = 0;
        ifstream myfile (argv[arg]);
        if (myfile.is_open())
        {
            string line;
            while ( getline (myfile,line) )
            {
                count++;
            }
            myfile.close();
            std::cout << " " << argv[arg] << ": " << count << '\n';
        }
        else
        {
            std::cout << argv[arg] << ": -1" << '\n';
        }
    }

    exit(0); // this means that the program executed correctly!
}
