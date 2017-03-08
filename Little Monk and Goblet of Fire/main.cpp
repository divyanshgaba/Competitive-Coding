#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


int main()
{
    int q;
    cin>>q;
    int k=0;
    queue<int> lane,school[5];
    queue<int> temp;
    for(int i =0;i<q;i++)
    {
        char c;
        int x,y;
        cin>>c;
        if(c=='D')
        {

            cout<<lane.front()<<" "<<school[lane.front()].front()<<endl;
            school[lane.front()].pop();
            if(school[lane.front()].empty())
                lane.pop();
        }
        else
        {
            cin>>x>>y;
            school[x].push(y);
            int flag =0;
            while(!lane.empty())
            {
                if(lane.front()==x)
                {
                    flag =1;
                }
                temp.push(lane.front());
                lane.pop();
            }
            while(!temp.empty()){
                lane.push(temp.front());
                temp.pop();
            }
            if(flag ==0)
                lane.push(x);

        }
    }
    return 0;
}
