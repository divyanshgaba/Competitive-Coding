#include <iostream>

using namespace std;
int c[101];
int main()
{
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        int temp;
        cin>>temp;
        c[temp]++;
    }
    int sum =0;
    for(int i =0;i<=100;i++)
    {
        sum+=(c[i]/2);
    }
    cout<<sum<<endl;
    return 0;
}
