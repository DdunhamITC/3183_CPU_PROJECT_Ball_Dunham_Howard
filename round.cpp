#include "round.h"
#include "adder.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <int> fpRound (float a)
    {   
        vector <int > flr;
        flr=ADDandSUB(a,1,3);
        return flr;
    }