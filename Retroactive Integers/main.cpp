#include <iostream>
#include <bits/stdc++.h>
#include <array>
#define MOD 1000000007
using namespace std;
struct item
{
    int t;
    char sym;
    long long x;
    long long y;
}a[100001];
int q;
bool mycom(item a,item b)
{
    return a.t<b.t;
}
int val[100001][20];
void print(item a)
{
    cout<<a.t<<" "<<a.sym<<" "<<a.x<<" "<<a.y<<endl;
}
void ans(item b[],int i)
{
    init();
  //  cout<<endl;
    vector<item> a;
    for(int j =0;j<i;j++)
    {
        if(b[j].t<b[i].t)
            a.push_back(b[j]);
    }
    sort(a.begin(),a.end(),mycom);
    for(vector<item> ::iterator it = a.begin();it!=a.end();it++)
    {
                       // for(int j =0;j<30;j++)                cout<<val[j]<<" ";
           // cout<<endl;
      //  print(*it);
        switch((*it).sym)
        {
            case '=':
                val[(*it).x] =val[(*it).y];
                break;
            case '*':
                val[(*it).x] = (val[(*it).x]*(*it).y)%MOD;
                break;
            case '+':
                val[(*it).x] =(val[(*it).x]+ (*it).y)%MOD;
                break;
            case '!':
                val[(*it).x] =(*it).y;
                break;
        }
    }
  //  print(b[i]);
    cout<<val[b[i].x]<<endl;
}
int main()
{
    cin>>q;
    init();
    for(int i =0;i<q;i++)
    {
        string s,v,c;
        cin>>a[i].t>>s>>v;
        a[i].sym = s[0];
        a[i].x = v[0]- 'a';
        if(s[0]!='?')
        {
            cin>>c;
        if(islower(c[0]))
            a[i].y =c[0]-'a';
        else
        {
            a[i].y = atoi(c.c_str());
        }
        }

        /*char c;
        char str[5][1000];
        int j=0;int k=0;
        while((c=getchar())!='\n')
        {
            //cout<<c<<" -"<<" ";
            if(c!=' ')
                str[k][j++]=c;
            else
            {
               str[k][j]='\0';
                k++;
                j=0;
            }
        }
        str[k][j]='\0';
        a[i].t =atoi(str[0]);
        a[i].sym = str[1][0];
        a[i].x = str[2][0] - 'a';
        if(k >2&&islower(str[3][0]))
            a[i].y =str[3][0] - 'a';
        else if(k>2)
            a[i].y =atoi(str[3]);
        else
            a[i].y =-1;*/
    }
    for(int i =0;i<q;i++)
    {
        if(a[i].sym =='?')
            ans(a,i);

    }
    return 0;
}
