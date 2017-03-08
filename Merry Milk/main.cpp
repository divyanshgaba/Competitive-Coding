/*
ID: divyans19
PROG: milk
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int n,m;
    fin>>n>>m;
    int total=0;
    vector<pair<int,int> > arr;
    for(int i=0;i<m;i++)
    {
        int price,unit;
        fin>>price>>unit;
        arr.push_back(make_pair(price,unit));
    }
    sort(arr.begin(),arr.end());
    while(n!=0)
    {
        for(vector<pair<int,int> >::iterator it = arr.begin();it != arr.end();it++)
        {
            if((*it).second < n)
            {
                total += ((*it).first)*((*it).second);
                n -=(*it).second;
            }
            else
            {
                total += (n)*(*it).first;
                n = 0;

            }
        }
    }
    fout<<total<<endl;
}
