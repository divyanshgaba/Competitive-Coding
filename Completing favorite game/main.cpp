#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n,h,t[1001];
stack<int> m[1001];
stack<int> game;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>h;
        for(int i =0;i<n;i++)
            cin>>t[i];
        for(int x=1;x<=n;x++)
        {
            int mx;
            cin>>mx;
            for(int i =0;i<mx;i++)
            {
                int temp;
                cin>>temp;
                m[x].push(temp);
            }
        }
        int day =1;
        game.push(1);
        int tsp =0;
        while(!game.empty())
        {
            int current = game.top();
            game.pop();
            tsp+=t[current];
            //cout<<current<<" --"<<endl;
            while(!m[current].empty())
            {
                int temp = m[current].top();
                if(tsp+t[temp]<=h)
                {
                    m[current].pop();
                    game.push(temp);
                    tsp+=t[temp];
                }
                else
                {
                    game.push(temp);
                    //m[current].pop();
                    tsp=0;
                    day++;
                }
            }
        }
        cout<<day<<endl;

    }
    return 0;
}
