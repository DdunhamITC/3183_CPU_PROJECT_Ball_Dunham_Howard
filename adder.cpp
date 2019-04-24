#include <iostream>
#include "adder.h"
#include <vector>
#include <cmath>
using namespace std;

int fullADDS(int a, int b, int c);
int fullADDC(int a, int b, int c);
int fullSUBD(int,int,int);
int fullSUBB(int,int,int);

vector <int> rCA(vector<int> a,vector<int> b);
int rCAC(vector<int> a,vector<int> b);
vector <int> rCS(vector<int> a,vector<int> b);

int expA(vector<int>a,vector<int>b);
int expB(vector<int>a,vector<int>b);
vector <int> fexp(int exA,int exB, int car);

vector <int> mtaVA (int exA,int exB,vector<int>a,vector<int>b);
vector <int> twoCOMP(vector <int> bin,float inpt);

vector <int> dectofp(float decnum);
float fptodec(vector <int> fpin);

vector <int> recombo(int s, vector <int> ex, vector <int> mt);

vector <int> ADDandSUB(float inA,float inB,int sig);

/*=============================================================================================================*/
vector <int> ADDandSUB(float inA,float inB, int sig)
    {
        // start with initial values
        if (sig == 1) // signal sets if add or subtract
            {inB=-1*inB;}
        else
            {inB=inB;}
        
        
        vector <int> fpA;
        vector <int> fpB;
        // step 1 convert to fp
        fpA=dectofp(inA);
        fpB=dectofp(inB);
        // step 2 pull out exponets
        int exA = expA(fpA,fpB);
        int exB = expB(fpA,fpB);
        vector <int> mtA;
        vector <int> mtB;
        // step 3 pull out normalized manticas
        mtA=mtaVA(exA,exB,fpA,fpB);
        mtB=mtaVA(exB,exA,fpB,fpA);
        // step 4 sum mantica
        vector<int> sumMT;
        int carry;

        if (fpA[0]==1&&fpB[0]==0)
            {
                if (abs(inA)<abs(inB))
                    {
                        mtA=twoCOMP(mtA,inA);
                        sumMT=rCA(mtA,mtB);
                        carry = 0 /*rCAC(mtA,mtB)*/;
                        sumMT.erase(sumMT.begin());
                        sumMT.push_back(0);
                        for(int i = 0 ; i < 100; i++)
                            {
                                if (abs(inA)==pow(2,i))
                                    {
                                        sumMT.erase(sumMT.begin());
                                        sumMT.push_back(0);
                                        break;
                                    }
                            }
                    }
                else
                    {
                        mtB=twoCOMP(mtB,inA);
                        sumMT=rCA(mtA,mtB);
                        carry = 0 /*rCAC(mtA,mtB)*/;
                        sumMT.erase(sumMT.begin());
                        sumMT.push_back(0);
                        for(int i = 0 ; i < 100; i++)
                            {
                                if (abs(inA)==pow(2,i))
                                    {
                                        sumMT.erase(sumMT.begin());
                                        sumMT.push_back(0);
                                        break;
                                    }
                            }
                    }
            }
        else if (fpA[0]==0&&fpB[0]==1)
            {
                if (abs(inA)<abs(inB))
                    {
                        mtA=twoCOMP(mtA,inA);
                        sumMT=rCA(mtA,mtB);
                        carry = 0 /*rCAC(mtA,mtB)*/;
                        sumMT.erase(sumMT.begin());
                        sumMT.push_back(0);
                        for(int i = 0 ; i < 100; i++)
                            {
                                if (abs(inA)==pow(2,i))
                                    {
                                        sumMT.erase(sumMT.begin());
                                        sumMT.push_back(0);
                                        break;
                                    }
                            }
                    }
                else
                    {
                        mtB=twoCOMP(mtB,inA);
                        sumMT=rCA(mtA,mtB);
                        carry = 0 /*rCAC(mtA,mtB)*/;
                        sumMT.erase(sumMT.begin());
                        sumMT.push_back(0);
                        for(int i = 0 ; i < 100; i++)
                            {
                                if (abs(inA)==pow(2,i))
                                    {
                                        sumMT.erase(sumMT.begin());
                                        sumMT.push_back(0);
                                        break;
                                    }
                            }
                    }
            }
        else
            {
                sumMT=rCA(mtA,mtB);
                carry = rCAC(mtA,mtB);
            }
        
        
        // step 5 get final exponet
        vector <int> finEXP;
        for(int i = 0 ; i < 100; i++)
                            {
                                if (abs(inA)==pow(2,i))
                                    {
                                        finEXP= fexp(exA-1,exB,carry);
                                        break;
                                    }
                                else
                                    {
                                        finEXP= fexp(exA,exB,carry);
                                    }
                            }
         
        
        // step 6 get final sign
        int sign = 0;
        if (inA+inB < 0)
            sign = 1;
        else
            sign = 0;
        
        
        // step 7 recombine for final sum
        vector <int> sum;
        sum = recombo(sign,finEXP,sumMT);
        float sumDEC = fptodec(sum);
        
        /* // display for test
        cout << inA << " + " << inB << endl;
        cout << "FP A=";
        for(int i = 0 ; i < 32 ; i++)
            {
                cout << fpA[i] << " ";
                if (i == 0 || i == 8)
                    cout << "||";
            }
        cout << endl << "+"<<endl;
        cout << "FP B=";
        for(int i = 0 ; i < 32 ; i++)
            {
                cout << fpB[i] << " ";
                if (i == 0 || i == 8)
                    cout << "||";
            }

        cout << endl;
        cout << endl;
        cout<< "equals" << endl;
        cout << endl;

        cout<< "EXA=" << exA << endl;
        cout<< "EXB=" << exB << endl;

        cout << endl;
        cout << "MANT A=";
        for(int i = 0 ; i < 24 ; i++)
            cout << mtA[i];
        cout<< endl;
        cout << "MANT B=";
        for(int i = 0 ; i < 24 ; i++)
            cout << mtB[i];
        
        cout<< endl;
        cout<< endl;
        cout << "MANT SUM=";
        for(int i = 0 ; i < 24 ; i++)
            cout << sumMT[i];
        cout<< endl;
        cout << "CARRY=";
        cout << carry << endl;
        cout << "FINISHED EXP=";
        for(int i = 0 ; i < 8 ; i++)
            cout << finEXP[i];
        cout<< endl;
        cout << "SIGN=";
        cout << sign << endl; 
        cout << "FINISHED SUM=";
        for(int i = 0 ; i < 32 ; i++)
            {
                cout << sum[i] << " ";
                if (i == 0 || i == 8)
                    cout << "||";
            }
        cout<< endl;
        cout << "SUM FP CONVERT=";
        cout << sumDEC << endl;
        cout << "RAW SUM=";
        cout << inA+inB << endl; */
        
        

        return sum;
    }
/*========================================================================================================*/
int fullADDS(int a, int b, int c)// just a case statement built from truth tables for both add and subtract
    {
        int sum;
        int car;
        if (a==1&&b==1&&c==1)
            {
                sum=1;
                car=1;
            }
        else if (a==1&&b==1&&c==0)
            {
                sum=0;
                car=1;
            }

        else if (a==1&&b==0&&c==1)
            {
                sum=0;
                car=1;
            }

        else if (a==1&&b==0&&c==0)
            {
                sum=1;
                car=0;
            }
        else if (a==0&&b==1&&c==1)
            {
                sum=0;
                car=1;
            }
        else if (a==0&&b==1&&c==0)
            {
                sum=1;
                car=0;
            }
        
        else if (a==0&&b==0&&c==1)
            {
                sum=1;
                car=0;
            }
        
        else
            {
                sum=0;
                car=0;
            }
        
        return sum;
    }
int fullADDC(int a, int b, int c)
    {
        int sum;
        int car;
        if (a==1&&b==1&&c==1)
            {
                sum=1;
                car=1;
            }
        else if (a==1&&b==1&&c==0)
            {
                sum=0;
                car=1;
            }

        else if (a==1&&b==0&&c==1)
            {
                sum=0;
                car=1;
            }

        else if (a==1&&b==0&&c==0)
            {
                sum=1;
                car=0;
            }
        else if (a==0&&b==1&&c==1)
            {
                sum=0;
                car=1;
            }
        else if (a==0&&b==1&&c==0)
            {
                sum=1;
                car=0;
            }
        
        else if (a==0&&b==0&&c==1)
            {
                sum=1;
                car=0;
            }
        
        else
            {
                sum=0;
                car=0;
            }
        
        return car;
    }
int fullSUBD(int a, int b, int c)
    {
        int sum;
        int car;
        if (a==1&&b==1&&c==1)
            {
                sum=1;
                car=1;
            }
        else if (a==1&&b==1&&c==0)
            {
                sum=0;
                car=0;
            }

        else if (a==1&&b==0&&c==1)
            {
                sum=0;
                car=0;
            }

        else if (a==1&&b==0&&c==0)
            {
                sum=1;
                car=0;
            }
        else if (a==0&&b==1&&c==1)
            {
                sum=0;
                car=1;
            }
        else if (a==0&&b==1&&c==0)
            {
                sum=1;
                car=1;
            }
        
        else if (a==0&&b==0&&c==1)
            {
                sum=1;
                car=1;
            }
        
        else
            {
                sum=0;
                car=0;
            }
        
        return sum;
    }

int fullSUBB(int a, int b, int c)
    {
        int sum;
        int car;
        if (a==1&&b==1&&c==1)
            {
                sum=1;
                car=1;
            }
        else if (a==1&&b==1&&c==0)
            {
                sum=0;
                car=0;
            }

        else if (a==1&&b==0&&c==1)
            {
                sum=0;
                car=0;
            }

        else if (a==1&&b==0&&c==0)
            {
                sum=1;
                car=0;
            }
        else if (a==0&&b==1&&c==1)
            {
                sum=0;
                car=1;
            }
        else if (a==0&&b==1&&c==0)
            {
                sum=1;
                car=1;
            }
        
        else if (a==0&&b==0&&c==1)
            {
                sum=1;
                car=1;
            }
        
        else
            {
                sum=0;
                car=0;
            }
        
        return car;
    }

vector <int> rCA(vector<int> a,vector<int> b)//ripple carry adder used for mantica only
    {
        //int carsize;
        //int as=a.size();
        //int bs=b.size();
        //vector <int> rsa;
        //vector <int> rsb;
        /* if (as > bs)// checking size of both arrays
            {
                for (int i = 0 ; i < as; i++)
                    {
                        if ((i-(bs-1)) <0)
                            rsb.push_back(0);
                        else
                            rsb.push_back(b[i-(bs-1)]);
                        rsa.push_back(a[i]);
                    }

                
            }

            else if (as < bs)
            {
                for (int i = 0 ; i < bs; i++)
                    {
                        if ((i-(as)) <0)
                            rsa.push_back(0);
                        else
                            rsa.push_back(a[i-(as)]);
                        rsb.push_back(b[i]);
                        
                    }
                
            }
        else
            {
                for (int i = 0; i < as;i++)
                    {   
                        rsa.push_back(a[i]);
                        rsb.push_back(b[i]);
                        
                    } 
            }
        if (as>bs)
            {
                carsize = as+1;
            }
        else if (as<bs)
            {
                carsize = bs+1;
            }
        else
            {
                carsize = as+1;
            } */
        
        vector<int> c;
        vector <int> s;
        for (int i = 0 ; i < 25; i++)
            {
                c.push_back(0);
                s.push_back(0);
            }
        
        for(int i = 24 ; i >= 0 ; i--)// running addition function
            {
                s[i]=(fullADDS(a[i-1],b[i-1],c[i]));
                c[i-1]=(fullADDC(a[i-1],b[i-1],c[i]));
            }
            vector <int> sum;
            if (c[0] == 1)
                {
                    for (int i = 0 ; i < 24; i++)
                        sum.push_back(s[i]);
                }
            else
                {
                    for (int i = 0 ; i < 24; i++)
                        sum.push_back(s[i+1]);
                }

        
        return sum;
    }

 vector <int> rCS(vector<int> a,vector<int> b)// ripple carry subtraction used for mantica only
    {
        //int carsize;
        int as=a.size();
        int bs=b.size();
        /* if (as > bs)// checking size of both arrays
            {
                for (int i = 0 ; i < as; i++)
                    {
                        if ((i-(bs-1)) <0)
                            rsb.push_back(0);
                        else
                            rsb.push_back(b[i-(bs-1)]);
                        rsa.push_back(a[i]);
                    }

                
            }

            else if (as < bs)
            {
                for (int i = 0 ; i < bs; i++)
                    {
                        if ((i-(as)) <0)
                            rsa.push_back(0);
                        else
                            rsa.push_back(a[i-(as)]);
                        rsb.push_back(b[i]);
                        
                    }
                
            }
        else
            {
                for (int i = 0; i < as;i++)
                    {   
                        rsa.push_back(a[i]);
                        rsb.push_back(b[i]);
                        
                    } 
            }
        if (as>bs)
            {
                carsize = as+1;
            }
        else if (as<bs)
            {
                carsize = bs+1;
            }
        else
            {
                carsize = as+1;
            }*/
        
        vector<int> c;
        vector <int> s;
        for (int i = 0 ; i < 25 ; i++)
            {
                c.push_back(0);
                s.push_back(0);
            }
        
        for(int i = as+1 ; i > -1 ; i--)// running addition function
            {
                s[i]=(fullSUBD(a[i-1],b[i-1],c[i]));
                c[i-1]=(fullSUBB(a[i-1],b[i-1],c[i]));
            }

        vector <int> sum;
            if (c[0] == 1)
                {
                    for (int i = 0 ; i < 24; i++)
                        sum.push_back(s[i]);
                }
            else
                {
                    for (int i = 0 ; i < 24; i++)
                        sum.push_back(s[i+1]);
                }

        
        return sum;
    } 

int rCAC(vector<int> a,vector<int> b)// carry out for addition
    {
        //int carsize;
        int as=a.size();
        int bs=b.size();
        //vector <int> rsa;
        //vector <int> rsb;
        /* if (as > bs)// checking size of both arrays
            {
                for (int i = 0 ; i < as; i++)
                    {
                        if ((i-(bs-1)) <0)
                            rsb.push_back(0);
                        else
                            rsb.push_back(b[i-(bs-1)]);
                        rsa.push_back(a[i]);
                    }

                
            }

            else if (as < bs)
            {
                for (int i = 0 ; i < bs; i++)
                    {
                        if ((i-(as)) <0)
                            rsa.push_back(0);
                        else
                            rsa.push_back(a[i-(as)]);
                        rsb.push_back(b[i]);
                        
                    }
                
            }
        else
            {
                for (int i = 0; i < as;i++)
                    {   
                        rsa.push_back(a[i]);
                        rsb.push_back(b[i]);
                        
                    } 
            }
        if (as>bs)
            {
                carsize = as+1;
            }
        else if (as<bs)
            {
                carsize = bs+1;
            }
        else
            {
                carsize = as+1;
            } */
        
        vector<int> c;
        vector <int> s;
        for (int i = 0 ; i < 25 ; i++)
            {
                c.push_back(0);
                s.push_back(0);
            }
        
        for(int i = as+1 ; i > -1 ; i--)// running addition function
            {
                s[i]=(fullADDS(a[i-1],b[i-1],c[i]));
                c[i-1]=(fullADDC(a[i-1],b[i-1],c[i]));
            }
        return c[0];
    }

vector <int> mtaVA (int exA,int exB,vector<int>a,vector<int>b) //pulling mantica for vector A
    {
        vector <int> mantA;
        vector <int> mant;
        int shift = abs(exA-exB);
        
                        for (int i = 8; i < 32; i++)
                            {
                                if (i==8)
                                    mantA.push_back(1);
                                else
                                    mantA.push_back(a[i]);
                            }
            if (exA<exB)
                {
                    for (int i = 0 ; i <= shift-1; i++)
                        mantA.insert(mantA.begin(),0);

                    for (int i = 0 ; i < 24 ; i++)
                        {
                            mant.push_back(mantA[i]);
                        }
                }
            else
                {
                    for (int i = 0 ; i < 24 ; i++)
                        {
                            mant.push_back(mantA[i]);
                        }
                }
            

        return mant;
    }



float fptodec(vector <int> fpin) // converts fp to decimal
{

    int sign;

    int check = 0;

    for (int i = 0 ; i < 32 ; i++)
    {
        check = check+fpin[i];
    }

    if (check == 0)
    {
        return 0;
    }

    if(fpin[0] == 1)
    {     sign = -1;   }
    else
    {     sign = 1;    }
    
    int expon = -127;
    
    int exponpower = 7;
    for(int i = 1; i < 9; i++)
    {
        expon = expon + fpin[i]*pow(2,exponpower);
        exponpower--;
    }
    
    float val;
    val = pow(2,expon);
    
    
    for(int i = 9; i < 32; i++){
        expon--;
        val = val + (fpin[i]* pow(2,expon));
        
    }
    
    val = val * sign;
    
    return val;
    
}

vector <int> dectofp(float decnum) // converts dec to fp
{

    vector <int> fp;
    vector <int> mant;
    vector <int> exponbin;

    int inters = floor(abs(decnum));
    float frac = abs(decnum) - inters;
    int expon;
    int fprev;

    if (decnum == 0)
    {
        for (int i = 0 ; i < 32 ; i ++)
            {
                fp.push_back(0);
            }
        return fp;
    }

    if(inters >= 1){
    expon = -1;
    while(inters >= 1){
        fprev = inters % 2;
        mant.insert(mant.begin(),fprev);
        inters = inters / 2;
        expon ++;
    }



    for(int i = 0; i < 23 - expon; i++){
        frac = frac * 2;
        if(frac >= 1){
            frac--;
            mant.push_back(1);
        }else{
            mant.push_back(0);
        }
    }

    }
    else{
    expon = 0;
    while(frac < 1){
        frac = frac * 2;
        expon--;
    }
    frac--;
    mant.push_back(1);
    for(int i = 0; i < 23 ; i++){
        frac = frac * 2;
        if(frac >= 1){
            frac--;
            mant.push_back(1);
        }else{
            mant.push_back(0);
        }
    }
    
    }

    int expon1 = expon + 127;
    int exprev;
    for(int i = 0; i < 8; i++){
        exprev = expon1 % 2;
        exponbin.insert(exponbin.begin(),exprev);
        expon1 = expon1 / 2;
    }

    if(decnum < 0){
    fp.push_back(1);
    }else{
    fp.push_back(0);
    }

    for(int i = 0; i < exponbin.size(); i++){
    fp.push_back(exponbin[i]);
    }
    for(int i = 1; i < mant.size(); i++){
    fp.push_back(mant[i]);
    }



    return fp; 
}

int expA(vector<int>a,vector<int>b) // pulling exponets from vectors
    {
       //int shR=0;
        // original for comparison
        /* for (int i = 0 ; i < 32 ; i++)
            {
                cout << a[i] << " ";
            }
        cout << endl;
        for (int i = 0 ; i < 32 ; i++)
            {
                cout << b[i] << " ";
            }
        cout << endl; */

        
        // how much to shift
        
        // looking at expontets to see which array to shift
        int exA=0;
        int exB=0;
        
        for (int i = 8 ; i > 0 ; i--)
            {
                exA = exA + a[i]*pow(2,8-i);
                exB = exB + b[i]*pow(2,8-i);
                
            }

        /* if (exA > exB)
            shR=exA-exB;
        else if (exA < exB)
            shR=exB-exA;
        else
            shR=0;
        

        if (exA < exB)
            {
                a.insert(a.begin()+9,1);
            }
        else if (exA > exB)
            {
                b.insert(b.begin()+9,1);
            }
        
        
        for (int i = 0 ; i < shR-1; i++)
            {
                if (exA < exB)
                    {
                        a.insert(a.begin()+9,0);
                    }
                else if (exA > exB)
                    {
                        b.insert(b.begin()+9,0);
                    }
                else
                    {
                        break;
                    }
                
            }
            // normalizing exponets
            if (exA < exB)
                    {
                        for (int i = 1; i < 9; i++)
                            {
                                a[i]=b[i];
                            }
                    }
                else if (exA > exB)
                    {
                        for (int i = 1; i < 9; i++)
                            {
                                b[i]=a[i];
                            }
                    }
                else{} */ 
        
       
        
    
        return exA;
    }

int expB(vector<int>a,vector<int>b) // pulling exponets from vectors
    {
        //int shR=0;
        // original for comparison
        /* for (int i = 0 ; i < 32 ; i++)
            {
                cout << a[i] << " ";
            }
        cout << endl;
        for (int i = 0 ; i < 32 ; i++)
            {
                cout << b[i] << " ";
            }
        cout << endl; */

        
        // how much to shift
        
        // looking at expontets to see which array to shift
        int exA=0;
        int exB=0;
        
        for (int i = 8 ; i > 0 ; i--)
            {
                exA = exA + a[i]*pow(2,8-i);
                exB = exB + b[i]*pow(2,8-i);
                
            }

       /*  if (exA > exB)
            shR=exA-exB;
        else if (exA < exB)
            shR=exB-exA;
        else
            shR=0;
        

        if (exA < exB)
            {
                a.insert(a.begin()+9,1);
            }
        else if (exA > exB)
            {
                b.insert(b.begin()+9,1);
            }
        
        
        for (int i = 0 ; i < shR-1; i++)
            {
                if (exA < exB)
                    {
                        a.insert(a.begin()+9,0);
                    }
                else if (exA > exB)
                    {
                        b.insert(b.begin()+9,0);
                    }
                else
                    {
                        break;
                    }
                
            }
            // normalizing exponets
            if (exA < exB)
                    {
                        for (int i = 1; i < 9; i++)
                            {
                                a[i]=b[i];
                            }
                    }
                else if (exA > exB)
                    {
                        for (int i = 1; i < 9; i++)
                            {
                                b[i]=a[i];
                            }
                    }
                else{} */
        
        // printing out completed arrays
       /*  for (int i = 0 ; i < 32 ; i++)
            {
                cout << a[i] << " ";
            }
        cout << endl;
        for (int i = 0 ; i < 32 ; i++)
            {
                cout << b[i] << " ";
            }
        cout << endl; */
    
        return exB;
    }

vector <int> fexp(int exA,int exB,int car) // produces final exponet
    {
        vector <int> binaryNumR; 
        vector <int> binaryNum; 
        int ex;
        int n;


        if (exA<exB)
            ex=exB;
        else
           ex=exA;
    
        if (car == 1)
            n=ex+1;
        else
            n=ex;
    

        // counter for binary array 
        int i = 8; 

        if (n==0)
            {
                for (int j = 0 ; j < i ; j++)
                    binaryNumR.push_back(0);
            }
        else
            {
                while (n > 0) 
                    {
                       // storing remainder in binary array 
                        binaryNumR.push_back(n % 2); 
                        n = n / 2; 
                    }
            }
  
        // printing binary array in reverse order 
        for (int j = i - 1; j >= 0; j--) 
            {
                if (binaryNumR[j]==1)
                    binaryNum.push_back(1);
                else
                    binaryNum.push_back(0);
            
            }
        
        return binaryNum;
        
    }

vector <int> recombo(int s, vector <int> ex, vector <int> mt) // produces final sum or dif full vector
    {
        vector <int> fin;

            fin.push_back(s);

            fin.push_back(ex[0]);
            fin.push_back(ex[1]);
            fin.push_back(ex[2]);
            fin.push_back(ex[3]);
            fin.push_back(ex[4]);
            fin.push_back(ex[5]);
            fin.push_back(ex[6]);
            fin.push_back(ex[7]);
            
            //fin.push_back(mt[0]);
            fin.push_back(mt[1]);
            fin.push_back(mt[2]);
            fin.push_back(mt[3]);

            fin.push_back(mt[4]);
            fin.push_back(mt[5]);
            fin.push_back(mt[6]);
            fin.push_back(mt[7]);

            fin.push_back(mt[8]);
            fin.push_back(mt[9]);
            fin.push_back(mt[10]);
            fin.push_back(mt[11]);

            fin.push_back(mt[12]);
            fin.push_back(mt[13]);
            fin.push_back(mt[14]);
            fin.push_back(mt[15]);

            fin.push_back(mt[16]);
            fin.push_back(mt[17]);
            fin.push_back(mt[18]);
            fin.push_back(mt[19]);

            fin.push_back(mt[20]);
            fin.push_back(mt[21]);
            fin.push_back(mt[22]);
            fin.push_back(mt[23]);


        /* for(int i = 0; i < 32; i++)
            {
                if (i == 0)
                    {
                        if (s==1)
                            fin.push_back(1);
                        else
                            fin.push_back(0);
                    }
                else if (i == 1 && i < 9)
                    {
                        fin.push_back(ex[i-1]);
                        if (ex[i-1]==0)
                            fin.push_back(0);
                        else
                            fin.push_back(1); 
                    }
                else
                    {
                        if (mt[i-8]==0)
                            fin.push_back(0);
                        else
                            fin.push_back(1);
                        
                    } 
                
            }*/

        return fin;
    }

vector <int> twoCOMP(vector <int> bin,float inpt)
    {
         
         vector <int> tCMP;
            
            if (inpt < 0)
                {
                    

                    vector <int> temp;
                    vector <int> one;
                    for (int i=0; i<23; i++)
                        {
                            if (i==22)
                                one.push_back(1);
                            else
                                one.push_back(0);
                            
                        }
                        
                    for (int i=0; i<23; i++)
                        {
                            if (bin[i]==1)
                                temp.push_back(0);
                            else
                                temp.push_back(1);
                            
                        }
                        
                    
                    tCMP=rCA(temp,one);
                    //tCMP.insert(tCMP.begin(),0);
                    /* tCMP.erase(tCMP.begin());
                    tCMP.push_back(0); */
                    
                    
                    
                    
                }
            else
                {
                    
                    tCMP=bin;
                }
            
            
        return tCMP;
    }