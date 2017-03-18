#include <iostream>

using namespace std;
int l,k;
//int ans[10001][10001];
int answer(int i,int cost)
{
    if(i==l)
    {
        if(cost==k)
            return 1;
        return 0;
    }
    if(cost>k)
        return 0;
    int temp =0;
    for(int j =i;j<=min(26,k)&&cost+j<=k;j++)
    {
        temp+= answer(j+1,cost+j);
    }
    return temp;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        //int k;
        cin>>l>>k;
        //if(ans[l][k]!=0)
          //  cout<<ans[l][k]<<endl;
        //else{
        //ans[l][k]=answer(0,0,0);
        cout<<answer(0,0)<<endl;

    }
    return 0;
}
