#include <iostream>
#include <cstring>
using namespace std;
int rup[101];
int ank[101];
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        memset(rup,0,sizeof(rup));
        memset(ank,0,sizeof(ank));
        int r[n],a[n];
        for(int i =0;i<n;i++)
        {
            cin>>r[i];
            rup[r[i]]++;
        }
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
            ank[a[i]]++;
        }
        int c=0;
        for(int i =1;i<101;i++)
        {
            if(rup[c]<=rup[i])
            {
                if(rup[c]==rup[i])
                    {if(c<i)
                        c=i;}
                else
                    c=i;
            }
        }
        int d=0;
        for(int i =1;i<101;i++)
        {
            if(ank[d]<=ank[i])
            {
                if(ank[d]==ank[i])
                    {if(d<i)
                        d=i;}
                else
                    d=i;
            }
        }
        if(c==d)
        {
            cout<<"Tie";
        }
        else if(c>d)
        {
            cout<<"Rupam";
        }
        else
        {
            cout<<"Ankit";
        }
        //cout<<c<<" "<<d<<endl;
        cout<<endl;
    }
    return 0;
}
