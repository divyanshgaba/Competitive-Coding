#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdbool.h>
using namespace std;

void findprimefactor(int n, vector<int> &vec)
{
    while(n%2 == 0)
    {
        vec.push_back(2);
        n /= 2;
    }
    for(int i =3;i<=sqrt(n);i++)
    {
        while(n%i == 0)
        {
            vec.push_back(i);
            n /= i;
        }
    }
    if(n != 1)
        vec.push_back(n);
}
void print_ele(int a)
{
    cout<<a<<" ";
}
void print_pair(pair <int,int> a)
{
    cout<<a.first<<" "<<a.second<<endl;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        vector<int> prfac;
        cin>>n;
        findprimefactor(n,prfac);
        sort(prfac.begin(),prfac.end());
        vector <int> uni = prfac;
        uni.erase(unique( uni.begin(), uni.end() ), uni.end());
        //for_each(prfac.begin(),prfac.end(),print_ele); cout<<endl;
        vector<int>::iterator it2 = prfac.begin();
        vector<pair <int,int> > count;
        for(vector<int>::iterator it = uni.begin();it != uni.end() && it2 != prfac.end();it++)
        {
            int temp =0;
            while(*it == *it2)
            {
                it2++;
                temp++;
            }
            count.push_back(make_pair(*it,temp));
        }
        vector<pair<int,int> >::iterator it = count.begin();
        int check = (*it).second;
        bool possible = true;
        if(check<2)
        {
            possible = false;
        }
        else
        {
            for(;it != count.end();it++)
            {
                 if(check != (*it).second)
                 {
                     possible = false;
                     break;
                 }
            }
        }
        if(possible)
            cout<<1;
        else
            cout<<0;
        cout<<endl;
        //for_each(count.begin(),count.end(),print_pair); cout<<endl;

    }
    return 0;
}
