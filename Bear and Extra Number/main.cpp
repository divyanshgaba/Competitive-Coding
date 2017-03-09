#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int hold;
        for(int i =1;i<n;i++)
        {
            if(a[i]!=(a[i-1]+1))
            {
                hold = i;
                break;
            }
        }
        if((hold==(n-1))||a[hold] != (a[hold+1]-1))
        {
            cout<<a[hold]<<endl;
        }
        else
            cout<<a[hold-1]<<endl;
    }
    return 0;
}
