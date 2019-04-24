#include "floor.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <int> fpFloor (vector <int> a)
    {
        int exA=0;
        if (a[0]==0)
            {
                for (int i = 8 ; i > 0 ; i--)
                    {
                        exA = exA + a[i]*pow(2,8-i);
                    }
                int ex = 127-exA;
                for (int i = 8+ex; i < 32;i++)
                    {
                        a[i]=0;
                    }
            }
    }