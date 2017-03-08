#include <iostream>

using namespace std;

int ans[115];

int answer(int n)
{
    if(n==10)
        return 1;
    if(n==12)
        return 1;
    if(n<10)
        return 10000;
    if(ans[n]!=0)
        return ans[n];
    int temp= min(1+answer(n-10),1+answer(n-12));
    ans[n]=temp;
    return temp;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int nen=answer(n);
        if(nen>10)
            cout<<"-1";
        else
            cout<<nen;
        cout<<endl;
    }
    return 0;
}
