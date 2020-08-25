#ifndef INTCODECOMPUTER_HPP
#define INTCODECOMPUTER_HPP
#include <cmath>
#include <vector>

using namespace std;

class IntcodeComputer
{
private:
    vector<int> intcode;

public:
    IntcodeComputer();
    IntcodeComputer(vector<int> codeIn);

    void setCode(vector<int> codeIn);

    vector<int> getOutCode();
    int getPosition();
};

#endif