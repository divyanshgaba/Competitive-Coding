/*
ID: divyans19
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
int a[1001];
int done[1001];
int b[1001];
int main()
{
    ifstream fin("skidesign.in");ofstream fout("skidesign.out");
    fin>>n;
    int max =-1;
    int min =101;
    for(int i =0;i<n;i++)
    {
        fin>>a[i];
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min =a[i];
    }
    int best_price = 12312412;
    for(int i =min;i<max;i++)
    {
        int price=0;
        for(int k =0;k<n;k++)
        {
            if(a[k] < i+17 && a[k] > i)
            {
                continue;
            }
            if(a[k]>i+17)
            {
                price += (a[k]-i-17)*(a[k]-i-17);
            }
            else if(a[k] < i)
            {
                price += (a[k] -i)*(a[k] - i) ;
            }
        }
        if(price < best_price)
            best_price =price;
    }
    fout<<best_price<<endl;
    return 0;
}
