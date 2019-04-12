# include <iostream>
# include <vector>
# include "reg.h"
using namespace std;

Register :: Register() // constructor just needed for access
    {}

void Register :: loading(int dat, int loc) // loading data into register
    {
        vector<int> vect = dec2_32BIN(dat);
        vector<int> binNUM;
        for (vector<int>::iterator it = vect.begin(); it !=vect.end(); ++it)
            binNUM.push_back(*it);

        for (int i = 0 ; i < binNUM.size() ; i++)
            {
                bNUM[i] = binNUM[i];
            }
        for (int i = 0 ; i < binNUM.size() ; i++)
        {
            r[loc][i]=bNUM[i];
        }
    }


void Register :: calling(int loc) // calling data from register
    {
        for (int i = 0 ; i < 32 ; i++)
        {
            binNUMout[i]=r[loc][i];
        }
    }

vector <int> Register :: dec2_32BIN(int data) // convert data to 32 bit binary
    {
                vector <int> binaryNum; 
                for (int i = 31; i >= 0; i--)
                    {
                        int k = data >> i; 
                        if (k & 1) 
                            binaryNum.push_back(1);
                        else
                            binaryNum.push_back(0);
                    }
            return binaryNum;
    }

void Register :: resetREG() // writes zeros to register or memory
    {
        for (int i = 0 ; i < size ; i++)
            {
                for (int j = 0 ; j < 32 ; j++)
                    {
                        r[i][j]=0; 
                    }
            }
    }

void Register :: dispREGS() // displays register used for testing purposes only not for main processor
    {
        for (int i = 0 ; i < size ; i++)
            {
                for (int j = 0 ; j < 32 ; j++)
                    {
                        cout << r[i][j] << " ";
                    }
                cout << endl;
            }
    }
