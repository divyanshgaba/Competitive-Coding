#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int n;
int a[51];
int visit[51];
int b[51];
float count =0;
int cost(int i)
{
    int sum =0;
    for(int i =n-1;i>=0;i--)
    {
        int count =1;
        for(int j =i-1;j>=0;j--)
        {
            if(b[i]<=b[j])
                break;
            count++;
        }
        sum+=count;
    }
    return sum;


}

float answer(int i )
{
    if(i==n)
    {
        count++;
        //cout<<cost(n-1)<<endl;
        return cost(n-1);
    }
    int temp =0;
    for(int j =0;j<n;j++)
    {
        if(visit[j]!=0)
            continue;
        if(visit[j]==0)
        {
            visit[j]=1;
            b[i]=a[j];
            temp+=answer(i+1);
            visit[j]=0;
        }
    }
    return temp;

}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        count=0;
        cin>>n;
        memset(visit,0,sizeof(visit));
        for(int i =0;i<n;i++)
            cin>>a[i];
        cout<<fixed;
        cout<<setprecision(2)<<answer(0)/count<<endl;
    }
    return 0;
}
