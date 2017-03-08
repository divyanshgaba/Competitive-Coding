#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    queue<pair<int,int> > a;
    queue<pair<int,int> > b;
    for(int i =1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        a.push(make_pair(temp,i));
    }
    for(int i =0;i<x;i++)
    {
        int j =0;
        pair<int,int> hold;
        hold = make_pair(-1,0);
        while(!a.empty()&&j<x)
        {
            b.push(a.front());
            pair<int,int> temp = a.front();
            if(hold.first<temp.first)
            {
                hold = temp;
            }
            a.pop();
            j++;
        }
        cout<<hold.second<<" ";
        while(!b.empty())
        {
            pair<int,int> temp = b.front();
            if(temp != hold)
            {
                if(temp.first >0)
                    temp.first -=1;
                a.push(temp);
            }
            b.pop();
        }
    }
    cout<<endl;
    return 0;
}
