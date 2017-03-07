/*
ID: divyans19
PROG: namenum
LANG: C++
*/
#include <iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdbool.h>
#include<algorithm>
#include<vector>
#include<ctype.h>
using namespace std;
ifstream fin("namenum.in");ofstream fout("namenum.out");
char arr[][3] = {{'A','B','C'},
                                {'D','E','F'},
                                {'G','H','I'},
                                {'J','K','L'},
                                {'M','N','O'},
                                {'P','R','S'},
                                {'T','U','V'},
                                {'W','X','Y'}   };
void generate_word(long long n,vector <string> &s)
{
    vector<int> digit;
    while(n!=0)
    {
        digit.insert(digit.begin(),n%10);

        n /= 10;
    }
   /* for(vector<int>::iterator it = digit.begin(); it != digit.end(); ++it)
    {
        fout<<*it<<" ";
    }*/
    int len;
    int size = digit.size();
    //fout<<size<<endl;
    vector <string> hold;
    for(vector<string>::iterator it = s.begin();it !=s.end();++it)
    {
        for(len = 0;(*it)[len]!='\0';len++);
        if(len == size)
        {
            hold.push_back(*it);
            //fout<<(*it)<<endl;
        }
    }
    int flag2 = 1;
    for(vector<string>::iterator it =hold.begin();it != hold.end();++it)
    {
        int flag =1;
        for(int i = 0;i<size;i++)
        {
            if(((*it)[i] == arr[digit[i] - 2][0])||((*it)[i] == arr[digit[i] - 2][1])||((*it)[i] == arr[digit[i] - 2][2]))
                continue;
            flag =0;
            break;
        }
        if(flag)
        {
            flag2 = 0;
            fout<<*it<<endl;
        }
    }
    if(flag2)
    {
        fout<<"NONE"<<endl;
    }


}

int main()
{

    long long n;
    fin>>n;
    ifstream dic("dict.txt");
    vector<string> hold;
    string s;
    while(!dic.eof())
    {
        char s[45];
        dic>>s;
      //  fout<<s<<endl;
        hold.push_back(s);
    }
    generate_word(n,hold);

    return 0;
}
