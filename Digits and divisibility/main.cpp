#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct suffix
{
    int index;
    int rank[2];
};

bool cmp(struct suffix a,struct suffix b)
{
    return (a.rank[0]==b.rank[0])?((a.rank[1]<b.rank[1])?1:0):
        ((a.rank[0]<b.rank[0])?1:0);
}

int* suffix(string s,int n)
{
    struct suffix suf[n];
    for(int i =0;i<n;i++)
    {
        suf[i].index = i;
        suf[i].rank[0] = s[i]-'a';
        suf[i].rank[1] = ((i+1) < n)? (s[i+1]-'a'):-1;
    }
    sort(suf,suf+n,cmp);
    int ind[n];
    for(int k =4;k<2*n;k*=2)
    {
        int rank =0;
        int pr_rank = suf[0].rank[0];
        suf[0].rank[0] = rank;
        ind[suf[0].index] = 0;
        for(int i =1;i<n;i++)
        {
            if(suf[i].rank[0] == pr_rank &&
               suf[i].rank[1] == suf[i-1].rank[1])
            {
                pr_rank =suf[i].rank[0];
                suf[i].rank[0]=rank;
            }
            else
            {
                pr_rank = suf[i].rank[0];
                suf[i].rank[0] = ++rank;
            }
            ind[suf[i].index]=i;
        }
        for(int i =0;i<n;i++)
        {
            int nex =suf[i].index + k/2;
            suf[i].rank[1] = nex<n? suf[ind[nex]].rank[0]:-1;
        }
        sort(suf,suf+n,cmp);
    }
    int * sufar = new int[n];
    for(int i =0;i<n;i++)
    {
        sufar[i] =suf[i].index;
    }
    return sufar;
}
bool pr[26];
int main()
{
	fast;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int* sar = suffix(s,n);
    int j =0;
    for(int i =sar[n-1];i<n;i++)
    {
        if(!pr[s[i]-'a']&&j!=n-1)
        {
            cout<<s[i];
            j++;
            pr[s[i]-'a']=true;
        }
    }
    cout<<endl;
	return 0;

}
