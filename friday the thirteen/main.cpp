/*
ID: divyans19
PROG: friday
LANG: C++
*/
#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>
#include<assert.h>
using namespace std;

int count[7];

int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    //ifstream cin("friday.in");
   // ofstream cout("friday.out");
    int n;
    cin>>n;
    assert(n>0 &&n<=400);
    memset(count,0,7);
    int day_13 = 0;
    for(int i = 1900;i<1900+n;i++)
    {
            for(int j = 0;j<12;j++)
            {

                count[day_13]++;
                day_13 = (day_13 + month[j])%7;
                if(j==1)
                {
                    if(i%100==0)
                    {
                        if(i%400==0)
                            day_13 = (day_13 + 1)%7;
                    }
                    else if(i%4==0)
                    {
                        day_13 = (day_13 + 1)%7;
                    }
                }

            }
    }
    int i;
    for(i=0;i<6;i++)
        cout<<count[i]<<" ";
    cout<<count[i]<<endl;
    return 0;
}
