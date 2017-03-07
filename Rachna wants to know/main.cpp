#include <iostream>
#define MOD 10000007
#define MAX 9000
using namespace std;
int memo[MAX+1][MAX+1];

int sum(int k, int n)
{

    if(n<MAX&&k<MAX&&memo[k][n]!=0)
        return memo[k][n];
    if(k == 1 || n == 1)
        return 1;
    int counter = 0;
    if(k < n)
        counter = sum (k, k)%MOD;
    else if (k == n)
        counter= 1 + sum (k, k-1)%MOD;
    else
        counter= (sum (k,n-1)%MOD + sum (k-n, n)%MOD)%MOD;
    if(n<MAX&&k<MAX)
        memo[k][n]=counter;
    return counter;
}

int main()
{
    int n;
    cin>>n;
    cout<<sum(n,n)%MOD-1<<endl;
    return 0;
}
