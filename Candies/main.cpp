#include <iostream>

using namespace std;
int r[100001];
int c[100001];
int main()
{
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
            cin>>r[i];
    }
    c[0]=1;
    for(int i =1;i<n;i++)
    {
        if(r[i]>r[i-1])
            c[i]=c[i-1]+1;
        else
            c[i]=1;
    }
    for(int i =1;i<n;i++)
    {
        if(r[i]<r[i-1] && c[i]==1)
        {
            for(int j =i-1;j>0;j--)
            {
                if(r[j]>r[j-1])
                    break;
                c[j]+=1;

            }
        }
    }
    int sum=0;
    for(int i =0;i<n;i++){
        sum+=c[i];
        //cout<<c[i]<<" ";
        }
    cout<<sum<<endl;
    return 0;
}
