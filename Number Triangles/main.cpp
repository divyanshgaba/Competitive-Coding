#include <iostream>
#include <cmath>
using namespace std;
int a[5000];
int n;
long long nodes;
int answer(int i)
{
    cout<<a[i]<<" "<<i<<endl;
    if(i>nodes)
        return 0;
    return a[i]+max(answer(2*i+1),answer(2*i+2));
}
int main()
{
    cin>>n;
    nodes = pow(2,n-1)-1;
    for(int i =0;i<nodes;i++)
        cin>>a[i];
    cout<<answer(0)<<endl;
    return 0;
}
