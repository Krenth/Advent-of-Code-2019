#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "read_code.hpp"
#include "compute_code.hpp"

using namespace std;

int main ()
{
    string file;
    cout << "Enter file name: ";    // Enter the CSV file with the intcode listed.
    cin >> file;
    cout << endl << endl;
    
    int * intcode;
    int * result;
    int length = read_code(file, intcode);
    
    cout << endl << "Code:" << endl;
    for (int n = 0; n < length; n++)
    {
        cout << intcode[n] << ", ";
    }
    cout << endl << endl;
    
    char cont = 'y';
    
    while (cont == 'y' || cont == 'Y')
    {
        cout << "Enter Noun: ";
        cin >> intcode[1];
        cout << endl;
        cout << "Enter Verb: ";
        cin >> intcode[2];
        cout << endl << endl;

        result = compute_code(intcode, length);

        cout << "Position 0: " << result[0] << endl << endl;
        cout << "Continue?: ";
        cin >> cont;
        cout << endl << endl;
    }
    delete [] intcode;
    delete [] result;
}
