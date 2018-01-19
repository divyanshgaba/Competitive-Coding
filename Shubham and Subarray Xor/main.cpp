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
const int N = 901;
const int NN = N*N;
int n;
int a[N];
struct trienode
{
    struct trienode *child[2];
    trienode()
    {
        child[0]=child[1]=NULL;
    }
};
struct node
{
    struct trienode *root;
    node()
    {
        root = new trienode;
    }
};
void upgrage(struct trienode* prev, struct trienode* cur, int k,int i)
{
    if(i==-1)
        return;
    if(prev == NULL)
    {
        for(;i>=0;i--)
        {
            bool isset = k&(1<<i);
            if(!cur->child[isset])
                cur->child[isset] = new trienode;
            cur=cur->child[isset];
        }
        return;
    }
    bool isset = k&(1<<i);
    cur->child[isset] = new trienode;
    cur->child[!isset] = prev->child[!isset];
    upgrage(prev->child[isset],cur->child[isset],k,i-1);
}
void insert(struct trienode* root,int k)
{
    trienode *cursor = root;
    for(int i = 31;i>=0;i--)
    {
        bool isset = k&(i<<1);
        if(!cursor->child[isset])
            cursor->child[isset] = new trienode;
        cursor=cursor->child[isset];
    }
}
int max_xor(struct trienode* root, int k)
{
    int ans = 0;
    struct trienode *cursor = root;
    for(int i = 31;i>=0;i--)
    {
        bool isset = k&(1<<i);
        if(cursor->child[isset]!=NULL)
        {
            ans |= (isset<<i);
            cursor = cursor->child[isset];
        }
        else if(cursor->child[!isset]!=NULL)
        {
            ans |= ((!isset)<<i);
            cursor = cursor->child[!isset];
        }
        else
        {
            return ans;
        }
    }
    return ans;
}
vector<int> subset[N];
node g[N];
int main()
{
	fast;
	cin>>n;
	for(int i = 0;i<n;i++)
        cin>>a[i];
    for(int i = 0;i<n;i++)
    {
        int prev = 0;
        for(int j = i;j<n;j++)
        {
            prev+=a[j];
            subset[i].PB(prev);
        }
    }
    for(int i = 0;i<subset[n-1].size();i++)
        insert(g[n-1].root,subset[n-1][i]);
    for(int i = n-2;i>=0;i--)
    {
        for(int j = 0;j<subset[i].size();j++)
        {
            if(!j)
                upgrage(g[i+1].root,g[i].root,subset[i][j],31);
            else
                upgrage(g[i].root,g[i].root,subset[i][j],31);
        }
    }
    /*for(int i = 0;i<n;i++)
    {
        for(auto j:subset[i])
            cout<<j<<" ";
        cout<<endl;
    }*/
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        int prev = 0;
        for(int j = i;j<n-1;j++)
        {
            prev += a[j];
            ans = max(ans,prev^max_xor(g[j+1].root,(~prev)^2147483648));
        }
    }
    cout<<ans<<endl;
	return 0;

}
