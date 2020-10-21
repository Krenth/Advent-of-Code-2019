#ifndef COMPUTE_CODE_HPP
#define COMPUTE_CODE_HPP
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int * compute_code(int * codein, int length)
{
    bool error = false;
    cout << "Loading IntCode to Computer...";
    int * codeout = new int [length];
    memcpy(codeout, codein, length*sizeof(int));
    cout << " Done Loading!" << endl << "Starting Computation..." << endl;

    for(int n = 0; !((codeout[n] == 99) || error); n+=4)
    {
        switch (codeout[n])
        {
            case 1:
                codeout[codeout[n+3]] = codeout[codeout[n+1]] + codeout[codeout[n+2]];
                cout  << "Add..." << endl;
                break;

            case 2:
                codeout[codeout[n+3]] = codeout[codeout[n+1]] * codeout[codeout[n+2]];
                cout << "Multiply..." << endl;
                break;
            
            default:
                cout << "Faulty IntCode!" << endl << "Stopping..." << endl;
                error = true;
                break;
        }
    }

    if (!error)
    {
        cout << "Computation Complete!" << endl;
    }

    return codeout;
}

#endif