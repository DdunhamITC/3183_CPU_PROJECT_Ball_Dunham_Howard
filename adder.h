#ifndef ADDER_H
#define ADDER_H


#include <iostream>
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

#endif