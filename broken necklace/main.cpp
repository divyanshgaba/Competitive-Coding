/*
ID: divyans19
PROG: beads
LANG: C++
*/
#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>
#include<assert.h>
using namespace std;

int main()
{
    //ifstream fin("beads.in");
    //ofstream fout("beads.out");
    int n;
    struct node* head = NULL;
    fin>>n;
    char s[n+5];
    fin>>s;
    int i,j;
    int max = 0;
    for(i = 0;i<n;i++)
    {
        int count = 0;
        char ch = s[i];
        for(j=i;j<n;j++)
        {
            if(ch=='w' && s[j]!='w')
            {
                count++;
                ch=s[j];
            }
            else if(s[j]=='w' || s[j] == ch)
            {
                count++;
            }
            else
            {
                ch=s[j];
                break;
            }
        }
        int flag =0;
        for(;j<n;j++)
        {
            if(ch=='w' && s[j]!='w')
            {
                count++;
                ch=s[j];
            }
            else if(s[j]=='w' || s[j] == ch)
            {
                count++;
            }
            else
            {
                flag=1;
                break;
            }
        }
        for(j=0;j<i&&flag==0;j++)
        {
            if(ch=='w' && s[j]!='w')
            {
                count++;
                ch=s[j];
            }
            else if(s[j]=='w' || s[j] == ch)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if(max < count)
        {
            max=count;
        }
    }
    fout<<max<<endl;



    return 0;
}
