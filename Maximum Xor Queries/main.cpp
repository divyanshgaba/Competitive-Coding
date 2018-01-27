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
const int N = 5e5+ 7;
const int Q = 5e5;
const int X = 1e9;
const int K = 1e9;
const int T = 4;
struct trienode
{
    struct trienode *child[2];
    int key;
    trienode()
    {
        child[0]=child[1]=NULL;
        key = 1;
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
    temp->key = 1;
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
            else
                cur->child[isset]->key+=1;
            cur = cur->child[isset];
        }
        return;
    }
    bool is = k&(1<<i);
    cur->child[is] =  new trienode;
    if(prev->child[is])
        cur->child[is]->key = 1 +  prev->child[is]->key;
    //cout<<cur->child[is]->key<<" "<<k<<" "<<i<<endl;
    cur->child[!is] = prev->child[!is];
    upgrade(prev->child[is],cur->child[is],k,i-1);
}
int mxor(struct trienode* root,int k)
{
    int ans = 0;
    struct trienode *cursor = root;
    for(int i =31;i>=0;i--)
    {
        bool isset = k&(1<<i);
        if(cursor->child[isset]!=NULL && (cursor->child[isset]->key)>0)
        {
            ans |= (isset<<i);
            cursor = cursor->child[isset];
        }
        else if(cursor->child[!isset]!=NULL && (cursor->child[!isset]->key)>0)
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
void deleteKey(trienode*prev, trienode*cur, int k,int i)
{
    if(i==-1)
        return;
    bool is = k&(1<<i);
    cur->child[is] =  new trienode;
    cur->child[is]->key = prev->child[is]->key - 1;
    //cout<<cur->child[is]->key<<" "<<prev->child[is]->key<<" "<<k<<" "<<i<<endl;
    cur->child[!is] = prev->child[!is];
    deleteKey(prev->child[is],cur->child[is],k,i-1);
}
node g[N];
int main()
{
	//fast;
	//freopen("input/input05.in","r",stdin);	freopen("output/output05.out","w",stdout);
	int q;
	cin>>q;
	assert(1<=q && q<=Q);
	for(int i = 1;i<=q;i++)
    {
        int t;
        cin>>t;
        //insert to list
        if(t==0)
        {
            int x;
            cin>>x;
            assert(1<=x && x<=X);
            upgrade(g[i-1].root,g[i].root,x,31);
        }
        //delete
        else if(t==1)
        {
            int x;
            cin>>x;
            //g[i]=g[i-1];
            assert(1<=x && x<=X);
            deleteKey(g[i-1].root,g[i].root,x,31);

        }
        // query
        else if(t==2)
        {
            int x;
            cin>>x;
            assert(1<=x && x<=X);
            g[i] = g[i-1];
            int ans = x^mxor(g[i].root,~x);
            assert(ans>=0);
            cout<<ans<<endl;
        }
        //undo
        else if(t==3)
        {
            int d;
            cin>>d;
            assert(1<=d && d<i);
            g[i]=g[i-d-1];
        }
        else
        {
            assert(0);
        }
    }
	return 0;

}
