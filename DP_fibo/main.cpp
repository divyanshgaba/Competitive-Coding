#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int a =0,b=1;
    for(int i =0;i<n;i++)
    {
        b=a+b;
        a=b-a;
    }
    cout<<a;
    return 0;
}
