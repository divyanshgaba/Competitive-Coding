/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
	fast;
	string s;
	cin>>s;
	int p = s.length();
	int n;
	cin>>n;
	int info[n];
	for(int i = 0;i<n;i++)
        cin>>info[i];
    int pre[p],suf[p];
    if(s[0]=='a'||s[0]=='o'||s[0]=='i'||s[0]=='e'||s[0]=='u')
    {
        pre[0]=1;
    }
    else
        pre[0]=0;
    if(s[p-1]=='a'||s[p-1]=='o'||s[p-1]=='i'||s[p-1]=='e'||s[p-1]=='u')
    {
        suf[p-1]=1;
    }
    else
        suf[p-1]=0;
    for(int i = 1;i<p;i++)
    {
        if(s[i]=='a'||s[i]=='o'||s[i]=='i'||s[i]=='e'||s[i]=='u')
        {
            pre[i]=pre[i-1]+1;
        }
        else
            pre[i]=pre[i-1];
    }
    for(int i = p-2;i>=0;i--)
    {
        if(s[i]=='a'||s[i]=='o'||s[i]=='i'||s[i]=='e'||s[i]=='u')
        {
            suf[i]=suf[i+1]+1;
        }
        else
            suf[i]=suf[i+1];
    }
    vector<ll>freq;
    freq.PB(0);
    for(int i = 0;i<n;i++)
    {
        int pos = abs(info[i]);
        if(info[i]<0)
            freq.PB(suf[pos]);
        else
            freq.PB(pre[pos]);
    }
    for(int i = 1;i<=n;i++)
        freq[i]+=freq[i-1];
    /*for(int i = 0;i<p;i++)
    {
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    for(int i = 0;i<p;i++)
    {
        cout<<suf[i]<<" ";
    }
    cout<<endl;
    for(int i = 0;i<=n;i++)
    {
        cout<<freq[i]<<" ";
    }
    cout<<endl;*/
    int m;
    cin>>m;
    while(m--)
    {
        int k;
        cin>>k;
        int ind = lower_bound(freq.begin(),freq.end(),k)-freq.begin()-1;
        //cout<<ind<<" ";
        if(k>=freq[ind])
            k-=freq[ind];
        //cout<<k<<" ";
        if(info[ind]>0)
        {
            int ans = lower_bound(pre,pre+p,k)-pre;
            cout<<s[ans];
            //cout<<ans<<endl;
        }
        else
        {
            int offset = -1*info[ind]  - 1;
            k += pre[offset];
            int ans = lower_bound(pre,pre+p,k) - pre;
            cout<<s[ans];
            //cout<<ans<<endl;
        }

    }
	return 0;

}
