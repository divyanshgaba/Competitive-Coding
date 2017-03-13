#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n,k;
string s;
map<pair<string,int>,int> yaad;
int init;
int mem[1000002];
int block()
{
    return *max_element(mem,mem+n);
}
void flip(int i)
{
    int j =i+1;
    while(j<n&&s[j]==s[i])
    {
        mem[j]-=mem[i];
        j++;
    }
    int hold = mem[i];
    s[i]=s[i]=='0'?'1':'0';
    if(i!=0&&s[i]==s[i-1])
    {
        mem[i]=mem[i-1]+1;
    }
    else
        mem[i]=1;
    j=i+1;
    while(j<n&&s[j]==s[i])
    {
        mem[j]+=mem[i];
        j++;
    }
}
int solve(int i,int k)
{

    if(yaad.count(make_pair(s,k))>0)
        return yaad[make_pair(s,k)];
    //cout<<s<<endl;
    if(k==0||i==n-1)
    {
        return block();
    }
    int temp;
    if(k!=0)
        temp = solve(i+1,k);
    if(k>0)
    {
        flip(i);
        temp =min(temp,solve(i+1,k-1));
        flip(i);
    }
    if(yaad.count(make_pair(s,k))>0)
        yaad[make_pair(s,k)]=min(yaad[make_pair(s,k)],temp);
    else
        yaad.insert(yaad.begin(),make_pair(make_pair(s,k),temp));
    return temp;

}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>k;
        init = k;
        cin>>s;
        memset(mem,0,sizeof(mem));
        mem[0]=1;
        for(int i =1;i<n;i++)
        {
            if(s[i]==s[i-1])
                mem[i]=mem[i-1]+1;
            else
                mem[i]=1;
            //cout<<mem[i]<<" ";
        }
        int ans=1;
        if(k>n/2)
        {
            ans=1;
        }
        else
        {
            k=k%n;
            k=min(k,n/2);
            ans = solve(0,k);
        }
        if(yaad.count(make_pair(s,k))>0)
            yaad[make_pair(s,k)]=min(ans,yaad[make_pair(s,k)]);
        else
            yaad.insert(yaad.begin(),make_pair(make_pair(s,k),ans));
        cout<<ans<<endl;
    }
    return 0;
}
