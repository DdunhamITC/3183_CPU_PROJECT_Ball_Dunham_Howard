vector <int> addCOMP(vector <int> fpa,vector <int> fpb )  

//int main()
    {
        int sig;
        // vector <int> fpa ;
        // vector <int> fpb ;
        vector <int> a ;
        vector <int> b ;

        //fpa = dectofp(8);
        //fpb = dectofp(8);

        

        for (int i = 8 ; i < 32 ; i++)
            {
                if (i == 8)
                    {
                        a.push_back(0);
                        b.push_back(0);
                        a.push_back(1);
                        b.push_back(1);
                    }
                else
                    {
                        a.push_back(fpa[i]);
                        b.push_back(fpb[i]);
                    }
            }
             

        vector <int> exA;
        vector <int> exB;

        for (int i = 1 ; i < 9 ; i++)
            {
                exA.push_back(fpa[i]);
                exB.push_back(fpb[i]);
            }
        if (fpa[0]==1 || fpb[0]==1)
            sig =1 ;
        else
            sig = 0;
        vector <int> exANS {0,0,0,0,0,0,0,0};
        
        int exINA=0;
        int exINB=0;
        int exINF=0;
        int shift=0;
                
                // getting exponet for final and shift
                int power=0;
                for (int i = exA.size()-1; i >=0 ; i--)
                    {
                            
                            exINA= exINA+exA[i]*pow(2,power);
                            
                            power= power+1;
                            
                    }
                
                power =0;
                for (int i = exA.size()-1; i >=0 ; i--)
                    {
                            
                            exINB= exINB+exB[i]*pow(2,power);
                            power= power+1;
                            
                    }
                if (exINA > exINB)
                    {
                        exINF=exINA;
                    shift= exINA-exINB;
                    for (int i; i < shift ;i++)
                        {
                            b.insert(b.begin(), 0);
                        }
                    b.resize(24);
                    }
                else
                    {
                        exINF=exINB;
                    shift = exINB-exINA;
                    for (int i; i < shift ;i++)
                        {
                            a.insert(a.begin(), 0);
                        }
                    
                    a.resize(24);   
                    }
                    // cout << exINA << " " << exINB << " " << exINF<< endl;
                    // cout << shift << endl;
                    
                
                
                vector <int> c;
                
                int ex = 0;
                        c.push_back(0);
        
                       
        
        int carry = 0;
        
        vector <int> ans{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int oF;

        if (sig == 1)
            {
                for (int i = ans.size()-1; i >=0;i--)
                {
                
                    if (i==0)
                    {
                        ans[i]=fullSUBD(0,0,carry);
                        oF=fullSUBB(0,0,carry);
                    }
                    else
                    {
                        ans[i]=fullSUBD(a[i-1],b[i-1],carry);
                        carry=fullSUBB(a[i-1],b[i-1],carry);
                    }
                    
                }
                    
                    
                    for (int i = 0 ; i < a.size() ; i++)
                        {if ((a[(a.size()-1)-i]+b[(a.size()-1)-i]+c[i])>1)
                        c.push_back(1);
                         else
                        c.push_back(0);}
                        if (c.at((a.size()-1))==0)
                            exINF=exINF-1;
                        cout << exINF << endl;
                    for (int i=7 ; i >=0 ; i--)
                {
                    exANS[i]=exINF%2;
                    exINF=exINF/2;
                    
                }
                    
                    
               ans.erase(ans.begin()); 
            }
        
        else
            {
                for (int i = ans.size()-1; i >=0;i--)
                {
                
                    if (i==0)
                    {
                        ans[i]=fullADDS(0,0,carry);
                        oF=fullADDC(0,0,carry);
                    }
                    else
                    {
                        ans[i]=fullADDS(a[i-1],b[i-1],carry);
                        carry=fullADDC(a[i-1],b[i-1],carry);
                    }
                }
                
                        for (int i = 0 ; i < a.size() ; i++)
                        {if ((a[(a.size()-1)-i]+b[(a.size()-1)-i]+c[i])>1)
                        c.push_back(1);
                         else
                        c.push_back(0);}
                        if (c.at((a.size()-1))==1)
                            exINF=exINF+1;
                        //cout << exINF << endl;
                    for (int i=7 ; i >=0 ; i--)
                {
                    exANS[i]=exINF%2;
                    exINF=exINF/2;
                    
                }
                    
            }

                
            

            

        

            ans.erase(ans.begin());
            ans.erase(ans.begin());
        for (int i = 0 ; i < ans.size();i++)
            {
                // cout<< ans[i] ;
            }
            
            // cout <<endl << ans.size() << endl;

            for (int i = 0 ; i < exANS.size();i++)
            {
                // cout<< exANS[i] ;
            }
            // cout <<endl << exANS.size() << endl;

        
        vector <int> recombo;
        for (int i = 0 ; i <32 ;i++)
            {
                if (i==0)
                    {
                        recombo.push_back(sig);
                    }
                else if (i>0 && i<9)
                    {
                        recombo.push_back(exANS[i-1]);
                    }
                else
                    {
                        recombo.push_back(ans[i-9]);
                    }
                
            }
            
            /* for ( int i =0 ; i < 32 ; i++)
                {
                    // cout << recombo[i];
                }
                cout << endl; */
        
        
        return recombo;
    }
