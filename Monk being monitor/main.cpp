#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 1000001

using namespace std;
int a[MAX];
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        memset(a,0,MAX);
        int max =0;
        for(int i =0;i<n;i++)
        {
            int hold;
            cin>>hold;
            if(max<hold)
                max=hold;
            a[hold]++;
        }

        sort(a,a+max+1,greater<int>());
        int i;
        //cout<<"hi"<<a[0]<<endl;
        for(i =0;i<max&&a[i]!=0;i++);
        cout<<((a[0]-a[i-1])==0?-1:a[0]-a[i-1])<<endl;

    }
    return 0;
}
