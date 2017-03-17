#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <algorithm>
#define MAX 100111
using namespace std;
int st[11][MAX];
int size[11];
stack<int> aux;
int n;
int binary(int i,int low,int high, int key)
{
    int mid;
    high--;
    while(low<high)
    {
        mid = (low+high)/2;
        if(st[i][mid]>key)
            high = mid;
        else
            low = mid+1;
    }
    if(st[i][low]>key)
        return low;
    return -1;
}
int ans()
{
    int min = aux.top();
    for(int i =1;i<n;i++)
    {
        int ans = binary(i,0,size[i],min);
        if(ans==-1)
            return false;
        else
            min = st[i][ans];
    }
    return true;
}
int main()
{
    cin>>n;
    int min0;
    for(int i =0;i<n;i++)
    {
        int x;
        cin>>x;
        size[i]=x;
        for(int j=0;j<x;j++)
        {
            cin>>st[i][j];
        }
    }

    aux.push(st[0][0]);
    for(int i =1;i<size[0];i++)
    {
        if(st[0][i]<aux.top())
        {
            aux.push(st[0][i]);
        }
        else
        {
            aux.push(aux.top());
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
            k--;
            st[k][size[k]]=h;
            size[k]++;
            if(k==0)
            {
                if(h<aux.top())
                {
                    aux.push(h);
                }
                else
                {
                    aux.push(aux.top());
                }
            }

        }
        else if(v==0)
        {
            int k;
            cin>>k;
            k--;
            size[k]--;
            if(k==0)
            {

                aux.pop();
                //cout<<"   "<<min0<<endl;
            }


        }
        else
        {

            if(ans())
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }

    }

    return 0;
}
