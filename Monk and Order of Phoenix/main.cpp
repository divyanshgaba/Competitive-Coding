#include <iostream>
#include <vector>
using namespace std;
bool master = true;
int ok[11];
int nge(vector<int> d,int low,int high,int key)
{
    int hold=high;
    int mid;
    while (low != high)
    {
        int mid = (low + high) / 2;
        if (d[mid] <= key)
        {

            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if(hold== high)
        return -1;
    return high;
}
int main()
{
    int n;
    cin>>n;
    vector<int> st[n];
    int sizes[n];
    for(int i =0;i<n;i++)
    {
        cin>>sizes[i];
        for(int j =0;j<sizes[i];j++)
        {
            int temp;
            cin>>temp;
            st[i].push_back(temp);
        }
    }
    int q;
    cin>>q;
    for(int i =0;i<q;i++)
    {
        int v;
        cin>>v;
        if(v==1)
        {
            int k,h;
            cin>>k>>h;
            st[k-1].push_back(h);
            sizes[k-1]++;
            if(ok[k-1]==1)
            {
                ok[k-1]=0;
                master = true;
            }
            //cout<<"v one "<<st[k-1].back()<<endl;

        }
        else if(v==0)
        {
           int k;
           cin>>k;
          // cout<<"v zero "<<st[k-1].back()<<endl;
           st[k-1].pop_back();
           sizes[k-1]--;
           if(sizes[k-1]==0||ok[k-1]==1)
           {
               master=false;
           }

        }
        else if(v==2)
        {
            bool cond = false;
            if(master){
                for(int l = 0;l<sizes[0];l++)
                {
                    int key=st[0][l];
                    if(key>st[1].back())
                        continue;
                    for(int h =1;h<n;h++)
                    {
                        cond = true;
                        if(key>st[h].back())
                        {
                            cond= false;
                            break;
                        }
                        int skey=nge(st[h],0,sizes[h],key);
                        if(skey == sizes[h]-1)
                        {
                            ok[h]=1;
                        }
                        if(skey <0)
                        {
                            cond =false;
                            break;
                        }
                        key = st[h][skey];
                    }
                    if (cond==true)
                    {
                        break;
                    }
                }
            }
            else
                cond =false;
            if(cond)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
