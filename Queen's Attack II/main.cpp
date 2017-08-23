#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    int ra,rb;
    cin>>ra>>rb;
    pair<int,int> obs[k];
    map<pair<int,int>, bool> mp;
    for(int i = 0;i<k;i++)
        cin>>obs[i].first>>obs[i].second,mp[obs[i]]= true;
    int ans = 0;
    for(int i = rb+1;i<=n;i++)
    {
        if(mp[make_pair(ra,i)] != true)
            ans++;
        else
            break;
    }
    for(int i = rb-1;i>0;i--)
    {
        if(mp[make_pair(ra,i)] != true)
            ans++;
        else
            break;
    }
    for(int i = ra+1;i<=n;i++)
    {
        if(mp[make_pair(i,rb)] != true)
            ans++;
        else
            break;
    }
    for(int i = ra-1;i>0;i--)
    {
        if(mp[make_pair(i,rb)] != true)
            ans++;
        else
            break;
    }
    for(int i = 1;i<n;i++)
    {
        if(ra + i >n || rb +i > n || mp[make_pair(ra+i,rb+i)]== true)
            break;
        ans++;
    }
    for(int i = 1;i<n;i++)
    {
        if(ra - i <= 0 || rb -i <=0 || mp[make_pair(ra-i,rb-i)]== true)
            break;
        ans++;
    }
    for(int i = 1;i<n;i++)
    {
        if(ra + i >n || rb -i<=0 || mp[make_pair(ra+i,rb-i)]== true)
            break;
        ans++;
    }
    for(int i = 1;i<n;i++)
    {
        if(ra -i<=0 || rb +i > n || mp[make_pair(ra-i,rb+i)]== true)
            break;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
