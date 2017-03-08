#include <iostream>
using namespace std;

int x[102],y[102];
int pr[102];
int n;
int minfert=0;
int fert[1001][1001];
int answer(int i,int p)
{
    if(p<minfert||i==n)
    {
            return p;
    }
    if(ans[i][p]!=0)
        return ans[i][p];
    return (ans[i][p]= max(answer(i+1,p),answer(i+1,p-y[i])+x[i]));

}
int cost(int i, int p)
{

}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int p;
        cin>>n>>p;
        minfert = 10001;
        for(int i =1;i<=n;i++)
        {
            cin>>x[i]>>y[i];
            pr[i] =x[i]-y[i];
            if(minfert>y[i])
                minfert=y[i];
        }
        int money =answer(0,p);
        int fcost = cost(0,money-p);
        cout<<fcost<<" "<<money<<endl;
    }
    return 0;
}
