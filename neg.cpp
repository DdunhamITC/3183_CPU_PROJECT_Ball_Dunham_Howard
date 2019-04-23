#include "neg.h"
#include <iostream>
#include <vector>
using namespace std;

vector <int> neg (vector <int> a)
    {
        if (a[0]==1)
            a[0]=0;
        else
            a[0]=1;
    
        return a;
    }