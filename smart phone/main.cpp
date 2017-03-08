#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long int budget[500000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>budget[i];
    sort(budget,budget+n);
    int temp=n/2;
    long long reven=budget[temp]*(n-temp);
    while(1)
    {
        if((budget[temp+1]*(n-temp-1))>=reven)
        {
            temp++;
            reven=budget[temp]*(n-temp);
        }
        else if((budget[temp-1]*(n-temp+1))<=reven)
        {
            temp--;
            reven=budget[temp]*(n-temp);
        }
        else
            break;
    }
    cout<<reven;
}
