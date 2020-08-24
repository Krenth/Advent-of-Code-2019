#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "include/read_masses.hpp"
#include "include/calculate_fuel.hpp"

using namespace std;

int main ()
{
    string file;
    cout << "Enter file name: ";
    cin >> file;
    cout << endl;

    vector<int> masses;
    read_masses(file, masses);
    int totalFuel = calculate_fuel(masses);
    cout << "Total Fuel Required: " << totalFuel << endl;
}

