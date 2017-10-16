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
const int N=1e4;
const int M = 5e3;
int f[M];
int cnt;
unordered_map<int,int> key;
vector<pair<int,int> > edge;
int m;
int arr[N];
int size[N];
void init()
{
    for(int i = 0;i<cnt;i++)
        arr[i]=i,size[i]=1;
}
int root(int n)
{
    while(arr[n]!=n)
        arr[n]=arr[arr[n]],n=arr[n];
    return n;
}
int special(int i)
{
    if(root(edge[i].first)==root(edge[i].second))
        return 1;
    return 0;
}
void connect(int a,int b)
{
    int r_a =root(a),r_b=root(b);
    if(r_a==r_b)
        return;
    if(size[r_a]<size[r_b])
        arr[r_a]=arr[r_b],size[r_b]+=size[r_a];
    else
        arr[r_b]=arr[r_a],size[r_a]+=size[r_b];
}
int ans(int st,int en,int k)
{
    init();
    for(int i = st;i<=en;i++)
    {
        if(i!=k)
            connect(edge[i].first,edge[i].second);
    }
    return special(k);
}
int bin(int low,int st,int k)
{
    int  high = m;
    int answer = m;
    while(low<high)
    {
        int mid = (low+high)/2;
        if(ans(st,mid,k))
            high=mid,answer = mid;
        else
            low=mid+1;
    }
    return answer;
}
int main()
{
    fast;
    int test=1;
    cin>>test;
    while(test--)
    {
        cin>>m;
        cnt=0;
        key.clear();
        edge.clear();
        for(int i = 0;i<m;i++)
        {
            pair<int,int> a;
            cin>>a.first>>a.second;
            if(key.count(a.first)==0)
                key[a.first]=cnt++;
            if(key.count(a.second)==0)
                key[a.second]=cnt++;
            edge.push_back({key[a.first],key[a.second]});
        }
        for(int i = 0;i<m;i++)
        {
            f[i]=0;
            for(int st = 0;st<=i;st++)
            {
                init();
                for(int k = st;k<i;k++)
                    connect(edge[k].first,edge[k].second);
                int en=i;
                int flag = 1;
                for(en = i;en<m;en++)
                {
                    if(en!=i)
                        connect(edge[en].first,edge[en].second);
                    if(special(i))
                    {
                        f[i]+=(m-en);
                        //cout<<i<<" "<<st<<" "<<en<<endl;
                        flag = 0;
                        break;
                    }

                }
                if(flag==1&&special(i))
                {
                    f[i]+=(m-en);
                    //cout<<i<<" "<<st<<" "<<en<<endl;
                    break;
                }
            }
        }
        for(int i = 0;i<m;i++)
            cout<<f[i]<<" ";
        cout<<endl;
    }
    return 0;
}
