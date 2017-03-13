#include <iostream>
#include <algorithm>
using namespace std;
int a[600];
int mem[600];
int n;
int answer(int i,int j)
{

cout<<i<<" "<<j<<endl;
    if(i>j)
        return 100000000;
    if(j==i)
        return 1;
    if(j==i+1)
    {
        if(a[j]==a[i])
            return 0;
    }
    int temp = 10000000;
    temp = min(temp,answer(i+1,j)+1);
    for(int k=i+1;k<=j;k++)
    {
        if(a[i]==a[k])
        {
            temp = min(temp,answer(i+1,k-1)+answer(k+1,j));
            break;
        }
    }
    return temp;

}
int main()
{
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<answer(0,n-1);
    return 0;
}
