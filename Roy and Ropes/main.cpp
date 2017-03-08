#include <iostream>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int l;
        cin>>l;
        int ans=0;
        int low[l+1];
        for(int i =1;i<l;i++)
        {
            cin>>low[i];
            low[i]+=i;
            if(ans<low[i])
                ans=low[i];
        }
        int up[l+1];
        for(int i =1;i<l;i++)
        {
            cin>>up[i];
            up[i]+=i;
            if(ans<up[i])
                ans=up[i];
        }
        if(ans<l)
            ans=l;
        cout<<ans<<endl;

    }
    return 0;
}

