#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
string s1,s2;
unordered_map<char,int> m2,cumilative[N];
bool possible(unordered_map<char,int> a,unordered_map<char,int> b)
{
    for(char i = 'A';i<='Z';i++)
    {
        if(b[i] - a[i] < m2[i])
            return false;
    }
    return true;
}

int answer(int i)
{
    int low = 1,high = s1.length();
    int ans = 2*s1.length();
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(possible(cumilative[i-1],cumilative[mid]))
        {
            ans = mid-i+1;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}

int main()
{
    cin>>s1>>s2;
    for(int i = 0;i<s2.length();i++)
        m2[s2[i]]++;
    for(int i = 1;i<=s1.length();i++)
    {
            cumilative[i].insert(cumilative[i-1].begin(),cumilative[i-1].end());
            cumilative[i][s1[i-1]]++;
    }
    int ans = 2*s1.length();
    for(int i = 1;i<=s1.length();i++)
    {
        //cout<<answer(i)<<" "<<i<<endl;
        ans = min(ans,answer(i));
    }
    if(ans<2*s1.length())
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
}
