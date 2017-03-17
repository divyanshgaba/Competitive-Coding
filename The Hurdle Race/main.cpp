#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    int max = *max_element(a,a+n);
    cout<<(k<max?max-k:0)<<endl;
    return 0;
}
