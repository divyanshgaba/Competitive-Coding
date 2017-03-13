#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>
#define MAX 100111
using namespace std;
int st[101][MAX];
int size[101];
int binary(int i,int low,int high, int key)
{
    int mid;
    while(low<high)
    {
        mid = (low+high)/2;
        if(st[i][mid]>key)
            high = mid;
        else
            low = mid+1;
    }
    if(st[i][low]>key)
        return st[i][low];
    return -1;
}

int main()
{
    int n;
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
            if(i==0)
            {
                if(j==0)
                    min0=st[0][j];
                else
                {
                    if(st[0][j]<min0)
                        min0=st[0][j];
                }
            }
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
            st[k-1][size[k-1]]=h;
            if(h<min0)
                min0=h;
            size[k-1]++;
        }
        else if(v==0)
        {
            int k;
            cin>>k;
            size[k-1]--;
            if(k==1)
            {
                if(st[0][size[0]]==min0)
                {
                    for(int i =0;i<size[0];i++)
                    {
                        if(i==0)
                            min0=st[0][i];
                        else
                        {
                            if(min0>st[0][i])
                                min0=st[0][i];
                        }
                    }
                }
                //cout<<"   "<<min0<<endl;
            }


        }
        else
        {
            bool val = true;
            if(size[0]==0)
            {
                cout<<"NO"<<endl;
                continue;
            }
            int getmin = min0;
            //cout<<getmin<<endl;
            for(int i =1;i<n;i++)
            {
                if(size[i]==0||st[i][size[i]-1]<getmin)
                {
                    val = false;
                    //cout<<"hi"<<i<<endl;
                    break;
                }
                else
                {
                    int temp = binary(i,0,size[i]-1,getmin);
                    //cout<<getmin<<endl;
                    if(temp!=-1)
                        getmin=temp;
                    else
                    {
                        val=false;
                        break;
                    }

                }
            }
            if(val)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }

    }

    return 0;
}
