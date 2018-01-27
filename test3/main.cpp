#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5+ 7;
const int Q = 5e5;
const int X = 1e9;
const int K = 1e9;
const int T = 4;
bool ok;
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
        ok = false;
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
    else
        ok = false;
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
    if(!prev->child[is])
    {
        ok = false;
        return;
    }
    cur->child[is]->key = prev->child[is]->key - 1;
    //cout<<cur->child[is]->key<<" "<<prev->child[is]->key<<" "<<k<<" "<<i<<endl;
    cur->child[!is] = prev->child[!is];
    deleteKey(prev->child[is],cur->child[is],k,i-1);
}
int getRandom(trienode* root)
{
    int ans = 0;
    trienode *cursor = root;
    for(int i =31;i>=0;i--)
    {
        bool isset = rand()%2;
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
            return -1;
        }
    }
    return ans;
}

int random()
{
    bool i = (rand()%100) < 25;
    if(i)
    {
        bool j = (rand()%100) < 75;
        if(j)
            return rand()%2;
        else
            return rand()%3;
    }
    return rand()%4;
}

node g[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    srand(time(NULL));
    //ofstream fout("output.out");
    //ifstream fin("input.in";)
    freopen("input/input04.in","wt",stdout);
    int q = (Q/10);
    cout<<q<<endl;
    int t;
    bool same = false;
    for(int i = 1;i<=q;i++)
    {
        if(!same)
            t=random();
        else
            same = false;
        //cout<<t<<endl;
        if(t == 0)
        {
            int x;
            ok = true;
            x = rand()%X + 1;
            g[i].root = new trienode;
            upgrade(g[i-1].root,g[i].root,x,31);
            if(ok)
            {
                i--;
                same = true;
                continue;
            }
            cout<<t<<" "<<x<<endl;
        }
        else if(t==1)
        {
            int x = getRandom(g[i-1].root);
            if(x==-1)
            {
                i--;
                continue;
            }
            deleteKey(g[i-1].root,g[i].root,x,31);
            cout<<t<<" "<<x<<endl;
        }
        else if(t==2)
        {
            int k = rand()%K + 1;
            g[i]=g[i-1];
            int ans = k^mxor(g[i].root,~k);
            assert(ans>=0);
            //cout<<ans<<endl;
            cout<<t<<" "<<k<<endl;
        }
        else if(t==3)
        {
            if(i==1)
            {
                i--;
                continue;
            }
            int d = rand()%i;
            while(!(1<=d && d<i))
                d=rand()%i;
            assert(1 <= d && d < i);
            g[i] = g[i-d-1];
            cout<<t<<" "<<d<<endl;
        }
        else
        {
            assert(0);
        }
    }

    //cout<< "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
return 0;
}
