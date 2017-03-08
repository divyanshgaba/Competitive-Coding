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
        int a[n];
        int hold =-1;
        int count =0;
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0&&hold==-1)
                hold=i;
            if(a[i]==1)
                count++;
        }
        int total = (n-count)*1000;
        if(hold !=-1)
            total += (n-hold)*100;
        cout<<total<<endl;
    }
    return 0;
}
