#include <iostream>
using namespace std;

int a[200001];
int divi[200001];
int n;
int check(int p,int q)
{



}
int main()
{
    cin>>n;
    for(int i =0;i<n;i++) cin>>a[i];
    int t;
    cin>>t;
    for(int i =0;i<t;i++)
    {
        int p,q;
        cin>>p>>q;
        cout<<check(p,q)<<endl;
    }
    return 0;
}
