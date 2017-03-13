#include <iostream>

using namespace std;

int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    k = k%n;
    int a[n];
    for(int i =0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<q;i++)
    {
        int m;
        cin>>m;
        cout<<a[(m-k)%n]<<endl;
    }
    return 0;
}
