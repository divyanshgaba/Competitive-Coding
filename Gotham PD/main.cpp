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
const int N = 300001;
const int INF = 2147483647;

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
    public:
    struct trienode *root;
    node()
    {
        root = new trienode;
    }
};
struct trienode* newTree(struct trienode *root)
{
    if(root == NULL)
        return root;
    trienode *temp = new trienode;
    temp->child[0] = newTree(root->child[0]);
    temp->child[1] = newTree(root->child[1]);
    return temp;
}

void upgrade(struct trienode* prev, struct trienode* cur,int k,int i)
{
    if(i==-1)
        return;
    if(prev == NULL)
    {
        //cout<<i<<" :(\n";
        for(;i>=0;i--)
        {
            bool isset = k&(1<<i);
            if(!cur->child[isset])
                cur->child[isset] = new trienode;
            cur = cur->child[isset];
        }
        return;
    }
    bool is = k&(1<<i);
    cur->child[is] =  new trienode;
    cur->child[!is] = prev->child[!is];
    upgrade(prev->child[is],cur->child[is],k,i-1);
}
void insert(struct trienode*root,int val)
{
    trienode *cursor = root;
    for(int i =31;i>=0;i--)
    {
        bool isset = val&(1<<i);
        if(!cursor->child[isset])
            cursor->child[isset] = new trienode;
        cursor = cursor->child[isset];
    }
}
int mxor(struct trienode* root,int k)
{
    int ans = 0;
    struct trienode *cursor = root;
    for(int i =31;i>=0;i--)
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
node g[N];
unordered_map<int,int> mp;
int main()
{
	//fast;
	int n,q;
	cin>>n>>q;
	int cnt =0;
	int r,k;
	cin>>r>>k;
	mp[r]=cnt++;
	insert(g[mp[r]].root,k);
	for(int i =0;i<n-1;i++)
    {
        int u,v,k;
        cin>>u>>v>>k;
        int ind = mp[u]=cnt++;
        //g[ind].root = newTree(g[mp[v]].root);
        upgrade(g[mp[v]].root,g[ind].root,k,31);
        //insert(g[ind].root,k);
    }
    int last =0;
    for(int i =0;i<q;i++)
    {
        int t;
        cin>>t;
        //actual value of t
        t^=last;
        if(t==0)
        {
            int v,u,k;
            cin>>v>>u>>k;
            //find real values
            u^=last;
            v^=last;
            k^=last;

            //add police station
            int ind = mp[u]=cnt++;
            //g[ind].root = newTree(g[mp[v]].root);
            upgrade(g[mp[v]].root,g[ind].root,k,31);
            //insert(g[ind].root,k);
        }
        else
        {
            int v,k;
            cin>>v>>k;
            //find real values;
            v^=last;
            k^=last;

            //compute answer and print
            int max_ans = k^mxor(g[mp[v]].root,~k^2147483648);
            int min_ans = k^mxor(g[mp[v]].root,k);
            cout<<min_ans<<" "<<max_ans<<endl;
            //update last
            last = min_ans ^ max_ans;

        }
    }

	return 0;

}
