#ifndef CALCULATE_FUEL_HPP
#define CALCULATE_FUEL_HPP
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

/** Calculate Additional Fuel
 * Calculates the additional fuel required for the part specific fuel.
 * 
 * COMMENT THIS FUNCTION OUT FOR PART ONE
 */
int calculate_additional_fuel (int partFuel)
{
    int additionalFuel = partFuel / 3 - 2;
    if (additionalFuel > 0)
    {
        additionalFuel += calculate_additional_fuel(additionalFuel);
    }
    else if (additionalFuel < 0)
    {
        additionalFuel = 0;
    }
    return additionalFuel;
}

/** Calculate Fuel
 * Calculates the part specific fuel requirements, and then the total fuel required for launch.
 * 
 */
int calculate_fuel (vector<int> &masses)
{
    int partFuel;
    int totalFuel = 0;
    cout << "Calculating Required Fuel for Parts..." << endl;
    for (vector<int>::iterator it = begin(masses); it != end(masses); ++it)
    {
        partFuel = *it / 3 - 2;
        
        // totalFuel += partFuel                                        // Part One
        totalFuel += partFuel + calculate_additional_fuel(partFuel);    // Part Two
        
        cout << *it << ": " << partFuel + calculate_additional_fuel(partFuel) << endl;
    }
    cout << "Calculated Required Fuel for Parts!" << endl << endl;
    return totalFuel;
}
#endif