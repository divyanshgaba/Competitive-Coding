#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findprimefactor(int n,vector<int,int> &vec)
{
    while(n%2 == 0)
    {
        vec.push_back(2);
        n /= 2;
    }
    for(int i =3;i<=sqrt(n);i++)
    {
        if(n%i == 0)
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
        for_each(prfac.begin(),prfac.end(),print_ele);
        cout<<endl;
    }
    return 0;
}
