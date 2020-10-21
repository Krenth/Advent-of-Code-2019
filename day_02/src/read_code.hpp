#ifndef READ_CODE_HPP
#define READ_CODE_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int read_code (const string &filename, int *&intcode)
{   
    fstream csvin;
    cout << "Opening File" << endl << endl;
    csvin.open(filename, iostream::in);

    string line;

    int * resizebuffer;

    intcode  = new int [8];
    int cnt = 0;
    int codesize = 8;

    while (getline(csvin, line, ','))
    {
        if (cnt == codesize)
        {
            resizebuffer = intcode;
            intcode = new int [codesize*3/2];
            memcpy(intcode, resizebuffer, codesize*sizeof(int));
            codesize += codesize/2;
            delete [] resizebuffer;
        }
        else if (cnt > codesize)
        {
            cout << "CSV Reading Error: Counter is Skipping!" << endl << "Returning NULL..." << endl;
            return 0;
            intcode = NULL;
        }
        intcode[cnt++] = stoi(line);
    }

    resizebuffer = intcode;
    intcode = new int [cnt];
    memcpy(intcode, resizebuffer, cnt*sizeof(int));
    codesize = cnt;
    delete [] resizebuffer;

    cout << "Finished Reading!" << endl << endl;
    return codesize;
}

#endif