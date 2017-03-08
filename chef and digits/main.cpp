#include <iostream>
#include <string.h>

using namespace std;


int main()
{
    int test;
    cin>>test;
    int r[test]={0};
    for(int i=0;i<test;i++)
    {
        int l;
        cin>>l;
        r[l-1]=1;
    }
    for(int i=0;i<test;i++)
    {
        if(r[i]==0)
            cout<<i+1<<' ';
    }
    cout<<endl;

    return 0;
}
