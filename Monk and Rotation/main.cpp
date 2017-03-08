#include <iostream>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,k;
        cin>>n>>k;
        k=k%n;
        int a[100001];
        for(int i =0;i<n;i++)
            cin>>a[i];
        for(int i =n-k;i<n;i++)
            cout<<a[i]<<" ";
        for(int i =0;i<n-k;i++)
            cout<<a[i]<<" ";
        cout<<endl;


    }
    return 0;
}
