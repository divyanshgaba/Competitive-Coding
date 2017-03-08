
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
        int a[n],b[n];
        for(int i = 0; i <n;i++)
        {
            cin>> a[i];
        }
       /* for(int i = 0;i<n ;i++)
        {
            b[i]= 5;
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j])
                {
                    if(b[i]<(b[j]+1))
                        b[i]=b[j]+1;
                }
            }

        }*/
        for(int i=0;i<n;i++)
            cout<<a[i];
        cout<<endl;
    }
}
