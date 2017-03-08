/*
ID: divyans19
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <stdlib.h>
#include <vector>
#include<fstream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

struct int_pair{

    int start,end;
};
bool compareInterval(int_pair i1, int_pair i2)
{
    return (i1.start < i2.start);
}
int main()
{
    //ifstream cin("milk2.in");
    //ofstream cout("milk2.out");
    int n;
    cin>>n;
    struct int_pair list[n];
    for(int i =0;i<n;i++)
    {
        cin>>list[i].start>>list[i].end;
    }
    sort(list, list+n,compareInterval);
    struct int_pair check[n];
    check[0]=list[0];
    int j=0;
    for(int i = 1;i<n;i++)
    {
            if((check[j].end >= list[i].start))
            {
                    if((check[j].end <= list[i].end ))
                        check[j].end = list[i].end;
            }
            else
                check[++j] = list[i];
           // cout<<list[i].start<<" "<<list[i].end<<endl;
    }
    int max=0,min=0;
   // cout<<"\n-----"<<endl;
    for(int i =0;i<=j;i++)
    {
     //   cout<<check[i].start<<" "<<check[i].end<<endl;
        if(max<check[i].end-check[i].start)
            max=check[i].end - check[i].start;
        if(i<j)
        {
            if(min==0)
            {
                ;
            }
            if(min<check[i+1].start -check[i].end)
                min = check[i+1].start - check[i].end;
        }
    }
    cout<<max<<" "<<min<<endl;
    return 0;
}
