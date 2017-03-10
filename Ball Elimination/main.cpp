#include <iostream>
#include <algorithm>
using namespace std;
int a[600];
int mem[600];
int n;
/*int answer(vector<int> a,int size)
{
    if(size<=1)
        return size;
    if(size ==2&&a[0]==a[1]&&a[0]!=0)
    {
        return 0;
    }
    else if(size ==2&&a[0]!=a[1])
    {
        return 2;
    }


}*/
int main()
{
    cin>>n;
    for(int i =1;i<=n;i++)
    {
        cin>>a[i];
    }
    int count=0;
    for(int j =1;j<=n;j++)
    {
        for(int i =1;i<n;i++)
        {
            if(a[i]==0)
                continue;
            if(a[i]==a[i+1])
            {
                a[i]=a[i+1]=0;
                for(int h=0;h<2;h++)
                {
                    for(int k =i+1;k>=1;k--)
                    {
                        swap(a[k],a[k-1]);
                    }
                }
                i--;
            }
        }
        for(int i =1;i<n-1;i++)
        {
            if(a[i]==0)
                continue;
            if(a[i]==a[i+2]&&a[i]!=a[i+1])
            {
                a[i+1]=0;
                for(int k =i+1;k>=1;k--)
                {
                    swap(a[k],a[k-1]);
                }
                count++;
                i--;
            }
        }

    }
    for(int i =1;i<=n;i++)
    {
        if(a[i]!=0)
        count++;
    }

    cout<<count;
    cout<<endl;
    return 0;
}
