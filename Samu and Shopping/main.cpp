#include <iostream>

using namespace std;
int items[100002][3];
int ans[100002][3];
int answer(int item,int shop,int n)
{
    if(shop == n)
    {
        return items[shop][item];
    }
    if(ans[shop][item]!=0)
        return ans[shop][item];
    int temp=items[shop][item];
    if(item == 0)
    {
        temp += min(answer(1,shop+1,n),answer(2,shop+1,n));
    }
    else if(item == 1)
    {
        temp += min(answer(0,shop+1,n),answer(2,shop+1,n));
    }
    else
    {
        temp += min(answer(1,shop+1,n),answer(0,shop+1,n));
    }
    ans[shop][item]=temp;
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
        for(int i =1;i<=n;i++)
        {
            cin>>items[i][0]>>items[i][1]>>items[i][2];
            ans[i][0]=ans[i][1]=ans[i][2]=0;
        }
        cout<<min(answer(0,1,n),min(answer(1,1,n),answer(2,1,n)))<<endl;
    }
    return 0;
}
