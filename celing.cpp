#include "celing.h"
#include "adder.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <int> fpCeling (float a)
    {   
        vector <int > flr;
        flr=ADDandSUB(a,1,2);
        return flr;
    }