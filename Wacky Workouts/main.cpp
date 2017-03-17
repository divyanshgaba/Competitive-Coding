#include <iostream>
#define MAX 1000000007
using namespace std;
int n;
int answer(int i,int g)
{
    if(i>=n-1)
        return 1;
    int temp =0;
    if(g)
        temp+=answer(i+1,!g);
    else
        temp+=(answer(i+1,!g) + answer(i+1,g));
    return temp;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        cout<<answer(0,1)+answer(0,0)<<endl;
    }
    return 0;
}
