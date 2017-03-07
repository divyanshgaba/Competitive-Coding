#include <iostream>
#define MAX 1000000009
using namespace std;
long long memo[10000002];
void ini()
{
    for(long long i =2;i<10000001;i++)
    {
        memo[i] =memo[i-2] + 4*(i)*(i) -6*(i-1);
        memo[i] %= MAX;
        if(memo[i]<0)
            memo[i]+=MAX;
    }
}
int main()
{
    int test;
    cin>>test;
    memo[1]=1;
    ini();
    while(test--)
    {
        long long n;
        cin>>n;
        cout<<memo[n]<<endl;
    }
    return 0;
}
