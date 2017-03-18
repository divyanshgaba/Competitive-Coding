#include <iostream>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int min=1e9+7,freq=0;
        for(int i =0;i<n;i++)
        {
            int x;
            cin>>x;
            if(min>x)
            {
                min = x;
                freq=1;
            }
            else if(min==x)
            {
                freq++;
            }
        }
        if(freq%2!=0)
        {
            cout<<"Lucky";
        }
        else
        {
            cout<<"Unlucky";
        }
        cout<<endl;
    }
    return 0;
}
