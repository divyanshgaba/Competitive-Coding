/*
ID: divyans19
PROG: gift1
LANG: C++
*/
#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>
using namespace std;
char s[20][20];
int np;
int mon[20];
int index(char *str)
{
    for(int i = 0;i<np;i++)
    {
        if(!strcmp(s[i],str))
            {
                return i;
            }
    }
    return -1;
}

int main()
{
    ifstream fin("gift1.in");
   ofstream fout("gift1.out");
    fin>>np;
    memset(mon,0,np);
    int i;
    for(i=0;i<np;i++)
        fin>>s[i];
    int cash,split;
    char giver[20];
    char reci[20];
    for(i=0;i<np;i++)
    {
        fin>>giver;
        fin>>cash>>split;
        if(cash!=0 && split!=0)
        {
            mon[index(giver)]+=(cash%split-cash);

        }
        for(int j = 0;j < split;j++)
        {
                fin>>reci;
                mon[index(reci)]+=cash/split;
        }

    }
    for(i = 0;i<np;i++)
    {
        fout<<s[i]<<" "<<mon[i]<<endl;
    }

    return 0;
}
