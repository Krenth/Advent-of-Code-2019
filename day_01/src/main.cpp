#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "read_masses.hpp"
#include "calculate_fuel.hpp"

using namespace std;

int main ()
{
    string file;
    cout << "Enter file name: ";    // Enter the CSV file with the masses listed (one per line).
    cin >> file;
    cout << endl;

    vector<int> masses;
    read_masses(file, masses);
    int totalFuel = calculate_fuel(masses);
    cout << "Total Fuel Required: " << totalFuel << endl;
}

