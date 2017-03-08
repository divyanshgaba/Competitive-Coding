#include <iostream>

using namespace std;


int main()
{
    int test;
    cin>>test;
    for(int j =1;j<=test;j++)
    {
        int n;
        cin>>n;
        int a[n];
        int b[n];
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
            b[i] = a[i]>>(1<<(1<<(1<<1)));
            a[i] = a[i]-(b[i]<<(1<<(1<<(1<<1))));

        }
        cout<<"Case "<<j<<":\n";
        for(int i =0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
         for(int i =0;i<n;i++)
            cout<<b[i]<<" ";
            cout<<endl;

    }
    return 0;
}
