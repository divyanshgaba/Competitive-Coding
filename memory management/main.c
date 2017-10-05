#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int p,s,n;
        cin>>p>>s>>n;
        vector<int> pages;
        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            pages.push_back(x/s);
        }
        int fifo = 0;
        queue<int> q;
        for(auto i:pages)
        {
            if(q.size()<p)
            {
                bool ans = false;
                for(int j = 0;j<q.size();j++)
                {
                    if(q.front()==i)
                        ans = true;
                    q.push(q.front()),q.pop();
                }
                if(!ans)
                    q.push(i);
                continue;
            }
            else
            {
                bool ans = false;
                for(int j = 0;j<p;j++)
                {
                    if(q.front()==i)
                        ans = true;
                    q.push(q.front()),q.pop();
                }
                if(!ans)
                    q.pop(),q.push(i),fifo++;
            }
        }
        deque<int> q2;
        int lru = 0;
        for(auto i:pages)
        {
            if(q2.size()<p)
            {
                bool ans = false;
                int k;
                int h = q2.size();
                for(int j = 0;j<h;j++)
                {
                    if(q2.front()==i)
                        ans = true,k = i, q2.pop_front();
                    else
                        q2.push_back(q2.front()),q2.pop_front();
                }
                if(!ans)
                    q2.push_front(i);
                else
                    q2.push_front(k);
                continue;
            }
            else
            {
                bool ans = false;
                int k;
                int h = q2.size();
                for(int j = 0;j<h;j++)
                {
                    if(q2.front()==i)
                        ans = true,k = i, q2.pop_front();
                    else
                        q2.push_back(q2.front()),q2.pop_front();
                }
                if(!ans)
                    q2.push_front(i),lru++,q2.pop_back();
                else
                    q2.push_front(k);
            }
        }
        if(lru<fifo)
            cout<<"yes ";
        else
            cout<<"no ";
        cout<<fifo<<" "<<lru<<endl;


    }
    return 0;
}
