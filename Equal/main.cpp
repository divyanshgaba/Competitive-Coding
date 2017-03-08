#include <iostream>

using namespace std;
int fab[1003];
int solve(int a)
{
    if(a==0)
        return 0;
    if(a==1||a==2||a==5)
        return 1;
    if(fab[a]!=0)
        return fab[a];
    int temp= 1;
    if(a>5)
    temp += min(solve(a-1),min(solve(a-2),solve(a-5)));
    else if(a>2)
        temp += min(solve(a-1),solve(a-2));
    else
        temp+= solve(a-1);
    fab[a]=temp;
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
        int a[n];
        int mini =1002;
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<mini)
                mini = a[i];
        }
        int temp=0;
        int count =0;
        for(int i =0;i<n;i++)
        {
                count+=solve(a[i]-mini);
                temp+=solve(a[i]);
        }
        cout<<min(temp,count)<<endl;


    }
    return 0;
}
