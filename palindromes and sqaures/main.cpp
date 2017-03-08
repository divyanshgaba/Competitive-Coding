/*
ID: divyans19
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <stdbool.h>
#define toNum(a) a>60?a-'A':a-'0'
#define toChar(a) a>9?a+'A':a+'0'
using namespace std;
//    ifstream cin("palsquare.in");   ofstream cout("palsquare.out");
char pad[50] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z'};
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
void print_elem(char elem)
{
    cout << elem;
}
void generate_base_n_num(int n)
{
    for(int i = 1; i<1000;i++)
    {
        vector<char> d;
        int temp2 = i*i;
        while(temp2!=0)
        {
            d.push_back(pad[temp2%n]);
            temp2 = temp2/n;
        }
        if(palindrome(d))
        {
            int temp =i;
            vector<char> c;
            while(temp!=0)
            {
                c.push_back(pad[temp%n]);
                temp = temp/n;
            }
            for_each(c.rbegin(),c.rend(),print_elem);
            cout<<" ";
            for_each(d.rbegin(),d.rend(),print_elem);
            cout<<endl;
        }


    }
}
int main()
{

    int n;
    cin>>n;
    generate_base_n_num(n);
    return 0;
}
