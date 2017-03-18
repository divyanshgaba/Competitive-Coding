#include<bits/stdc++.h>
using namespace std;
int gsum(int btree[], int index)
{
    int sum = 0;

    while (index > 0)
    {
        sum += btree[index];
        index -= index & (-index);
    }
    return sum;
}
void upbit(int btree[], int n, int index, int val)
{
    while (index <= n)
    {
       btree[index] += val;
       index += index & (-index);
    }
}
int answer(int arr[], int n)
{
    int ico = 0;
    int mel = 0;
    for (int i=0; i<n; i++)
        if (mel < arr[i])
            mel = arr[i];
    int BIT[mel+1];
    for (int i=1; i<=mel; i++)
        BIT[i] = 0;
    for (int i=n-1; i>=0; i--)
    {
        ico += gsum(BIT, arr[i]-1);
        upbit(BIT, mel, arr[i], 1);
    }

    return ico;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int flag =0,flag2=0;
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
            if(i!=0)
            {
                if(a[i-1]>a[i])
                    flag=1;
                if(a[i-1]<a[i])
                    flag2=1;
            }
        }
        if(flag==1&&flag2==1)
            cout<<answer(a,n)<<endl;
        else if(flag==0)
            cout<<"0"<<endl;
        else
            cout<<n<<endl;
    }
    return 0;
}
