#ifndef reg_H
#define reg_H

# include <iostream>
# include <vector>

using namespace std;

class Register // building a class for memory or registers it will work for either one
{
    private : // declaring all variables used in class
        int data;
        int location;
        int size =16;
        int r[16][32];
        int bNUM[32];
        int binNUMout[32];
        vector <int> binNUM;
    public: // declaring all functions in class
        Register(); 
        vector <int> dec2_32BIN(int);
        void loading(int dat,int loc);
        void calling(int loc);
        void resetREG();
        void dispREGS();
        int dispReg(int iter) { return binNUMout[iter];} // used for outputing to next block
};

#endif
