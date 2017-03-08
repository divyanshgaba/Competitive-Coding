#include <iostream>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--);
    {
        int g;
        cin>>g;
        while(g--)
        {
            int i,n,q;
            cin>>i>>n>>q;
            if(n%2==0)
            {
                cout<<n/2;
                break;
            }
            else
            {
                int k=n/2;
                if(i==q)
                    cout<<k;
                else
                    cout<<n-k;
            }

        }
    }
    return 0;
}
