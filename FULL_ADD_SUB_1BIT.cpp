 
 int fullADDS(int a, int b, int c);
    int fullADDC(int a, int b, int c);
    int fullSUBD(int,int,int);
    int fullSUBB(int,int,int);

 
 
 
 
 
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
