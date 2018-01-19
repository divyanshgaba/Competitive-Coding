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
const int limit = 128;
int freq[limit][1001];
int freqb[limit];
int freqc[limit];
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        memset(freq,0,sizeof(freq));
        memset(freqb,0,sizeof(freqb));
        memset(freqc,0,sizeof(freqc));
		string a,b;
		cin>>a>>b;
		freq[a[0]][0]++;
		for(int i = 1;i<a.size();i++)
        {
            freq[a[i]][i]++;
            for(int j = 0;j<limit;j++)
            {
                freq[j][i]+=freq[j][i-1];
            }
        }
        for(int i = 0;i<b.size();i++)
        {
            freqb[b[i]]++;
        }
        int n = a.size();
        int st = 0,len = n+5;
        for(int i = 0;i<n;i++)
        {
            int lo = i, hi = n-1;
            while(lo<=hi)
            {
                int mid = (lo+hi)/2;
                for(int j = 0;j<limit;j++)
                {
                    freqc[j] = freq[j][mid];
                    if(i!=0)
                        freqc[j] -= freq[j][i-1];
                }
                bool t = true;
                for(int j = 0;j<limit;j++)
                {
                    if(freqb[j]>freqc[j])
                    {
                        t= false;
                        break;
                    }
                }
                if(t)
                {
                    if(len >(mid-i+1))
                    {
                        len = mid-i+1;
                        st = i;
                    }
                    hi = mid-1;
                }
                else
                    lo=mid+1;
                //cout<<lo<<" "<<hi<<endl;
            }
        }
        if(len<n+1)
        {
            for(int i = st;i<st+len;i++)
                cout<<a[i];
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
	return 0;

}
