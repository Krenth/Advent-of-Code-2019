#ifndef READ_MASSES_HPP
#define READ_MASSES_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/** Read Masses
 * Opens and parses a CSV file, which defines the part masses in each line, into a vector<int>.
 * 
 */
void read_masses (const string &filename, vector<int> &masses)
{   
    fstream csvin;
    cout << "Opening File" << endl << endl;
    csvin.open(filename, iostream::in);

    string line;
    int mass;
    cout << "Start Reading..." << endl;
    while(getline(csvin, line))
    {
        mass = stoi(line);
        masses.push_back(mass);
    }
    cout << "Finished Reading!" << endl << endl;
}
#endif