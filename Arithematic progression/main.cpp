/*
ID: divyans19
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
int n;
int m;
int isb[125001];
ifstream fin("ariprog.in");ofstream fout("ariprog.out");
void factorize(int num, int a[])
{
    if(num == 0)
        return;
    while(num%2==0)
    {
        num /= 2;
        a[2]++;
    }
    int i;
    for(i =3;i<=sqrt(num);i+=2)
    {
        if(num%i ==0)
        {
            while(num%i == 0)
            {
                num /= i;
                a[i]++;
            }
        }
    }

    if(num != 1)
        a[num]++;

}
void print(int ele)
{
    fout<<ele<<" ";
}
bool isbisq(int num)
{
    int count[num+1]={};
    factorize(num,count);
    //fout<<num<<" "; for_each(a.begin(),a.end(),print); fout<<endl;
    /*for(int i =0;i<=num;i++)
    {
        fout<<i<<" "<<count[i]<<endl;
    }*/
    for(int i =3;i<=num;i+=4)
    {
        if(count[i] % 2 == 1)
            return false;
    }

    return true;
}

void print_pair(pair<int,int> a)
{
    fout<<a.second<<" "<<a.first<<endl;
}
int main()
{

    fin>>n>>m;
    vector<pair<int,int> > out;
    for(int i =0;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if(isbisq(i*i + j*j))
            {
                isb[i*i + j*j] =1;
            }
        }
    }

    //for_each(check.begin(),check.end(),print); fout<<endl;
    int max = (2*m*m);
    int hulk;
    int h =1;
    int mymain = 1;

    for(int j =1;j<=3000;j+=h )
    {
        //fout<<"j "<<j<<endl;
        int isap[max+1]={0};
        for(int x=0;x<=max;x++)
        {
                if(isb[x]!=1)
                    continue;
                int it = x;
                if(mymain ==0 && ((it)+hulk> max))
                {
                       break;
                }
                int num = it;
                int k;
                int flag =1;
                for(k =0;k<n;k++)
                {

                    if(num>max||isb[num] == 0)
                    {
                        break;
                    }
                    if(isap[num]!=1)
                        flag =0;
                    isap[num]=1;
                    num += j;
                }
                if(k>=n)
                {
                    if(flag==0)
                        out.push_back(make_pair(j,it));
                    if(mymain == 1)
                    {
                        mymain = 0;
                        h = j;
                        hulk = n*j;
                    }
                }
            }

    }
    if(!out.empty())
    {
        sort(out.begin(),out.end());
        out.erase(unique(out.begin(),out.end()),out.end());
        for_each(out.begin(),out.end(),print_pair);
    }
    else
        fout<<"NONE"<<endl;
    return 0;
}
