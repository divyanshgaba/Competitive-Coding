/*
ID: divyans19
PROG: combo
LANG: C++
*/
#include <iostream>
#include <stdbool.h>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <stdbool.h>
using namespace std;
ifstream fin("combo.in");ofstream fout("combo.out");
int n;
bool check(int a,int i)
{
    return abs(a-i) <=2 || abs(a-n-i) <=2 || abs(a-i+n)<=2;
}
bool checker(int a[3],int i,int j,int k)
{
    return ((check(a[0],i))&&(check(a[1],j))&&(check(a[2],k)));
}

int main()
{
    fin>>n;
    int farm[3],mast[3];
    for(int i =0;i<3;i++)
    {
        fin>>farm[i];
    }
    for(int i =0;i<3;i++)
    {
        fin>>mast[i];
    }
    int count = 0;
    for(int j =0;j<n;j++)
    {
            for(int k =0;k<n;k++)
            {
                for(int i =0;i<n;i++)
                {
                if(checker(farm,i,j,k) || checker(mast,i,j,k))
                    count++;
                }
            }
    }
    fout<<count<<endl;
}
