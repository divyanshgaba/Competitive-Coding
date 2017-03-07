/*
ID: divyans19
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include<cstring>
#include <fstream>
#include <stdbool.h>
#define toNum(a) a>60?a-'A':a-'0'
#define toChar(a) a>9?a+'A':a+'0'

using namespace std;
   ifstream fin("dualpal.in");   ofstream fout("dualpal.out");
char pad[50] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z'};
vector<int> data;
bool palindrome(vector<char> c)
{
    int n = c.size();
    for(int i =0;i<n/2;i++)
    {
        if(c[i] != c[n-1-i])
        {
            return false;
        }
    }
    return true;
}
void print_elem(int elem)
{
    fout << elem<<endl;
}

void generate_base_n_num(int n,int s)
{
    int cn =0;
    for(int i=s+1;cn<n;i++)
    {
        int count = 0;
        for(int j =2;j<=10;j++)
        {
            vector<char> d;
            int temp2 = i;
            while(temp2!=0)
            {
                d.push_back(pad[temp2%j]);
                temp2 = temp2/j;
            }
            if(palindrome(d))
            {
                count++;
            }
            if(count>=2)
            {
                break;
            }
        }
        if(count>=2)
        {
            data.push_back(i);

            cn++;

        }


    }
}
int main()
{

    int n,s;
    fin>>n>>s;
    generate_base_n_num(n,s);
    for_each(data.begin(),data.end(),print_elem);
    return 0;
}
