/*
ID: divyans19
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;

int to_string_len(int val,vector<int> dig)
{
    if(val == 0)
        return 0;
    if(!(find(dig.begin(), dig.end(), val%10) != dig.end()))
    {
        return 5;
    }
    return 1+ to_string_len(val/10,dig);


}
ifstream fin("crypt1.in");ofstream fout("crypt1.out");
int main()
{

    int n;
    fin>>n;
    vector<int> dig(n);
    for(int i =0;i<n;i++)
    {
        fin>>dig[i];
    }
    int count =0;
    for(int i =0;i<n;i++)
    {
        int a = dig[i];
        for(int j =0;j<n;j++)
        {
            int b = dig[j];
            for(int k =0;k<n;k++)
            {
                int c = dig[k];
                for(int l =0;l<n;l++)
                {
                    int d = dig[l];
                    for(int m =0;m<n;m++)
                    {
                        int e = dig[m];
                        int abce = e*a*100 + e*b*10 +e*c;
                        int abcd = d*a*100 +d*b*10 +d*c;
                        int abcde = abcd*10 + abce;
                        if(to_string_len(abce,dig)==3&&to_string_len(abcd,dig)==3&&to_string_len(abcde,dig)==4)
                        {
                           // fout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
                            count++;
                        }
                    }
                }
            }
        }

    }
    fout<<count<<endl;

    return 0;
}
