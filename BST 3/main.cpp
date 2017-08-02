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

struct node
{
    int val;
    struct node* left, *right;
    struct node* parent;
};

struct node* child(int val, node*root)
{
    node *temp = new node;
    temp->val = val;
    temp->left = temp->right = NULL;
    temp->parent = root;
    return temp;
}

struct node* insert_ele(node* root, int val, node* prev)
{
    if(root == NULL)
    {
        return child(val,prev);
    }
    if(val<=root->val)
        root->left = insert_ele(root->left, val,root);
    else
        root->right = insert_ele(root->right, val,root);
    return root;

}
void inorder(node*root)
{
    if(root == NULL)
        return;
    if(root->left!=NULL)
        inorder(root->left);
    cout<<root->val<<" ";
    if(root->right != NULL)
        inorder(root->right);

}
node* search_node(node* root, int val)
{
    node* temp = root;
    queue<node*> q;
    q.push(temp);
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        if(t->val == val)
            return t;
        if(t->left !=NULL)
            q.push(t->left);
        if(t->right != NULL)
            q.push(t->right);
    }
    return NULL;
}

int lca(node *a,node*b)
{
    map<node*,bool> mp;
    while(a!=NULL)
    {
        mp[a] = true;
        a = a->parent;
    }
    while(b!=NULL)
    {
        if(mp.count(b)>0)
            return b->val;
        b = b->parent;
    }
    return -1;
}

int main()
{
	fast;
    int n;
    cin>>n;
    node *root = NULL;
    for(int i = 0;i<n;i++)
    {
        int v;
        cin>>v;
        if(!root)
            root = insert_ele(root,v,NULL);
        else
            insert_ele(root,v,NULL);
    }
    //inorder(root);
    int x,y;
    cin>>x>>y;
    auto a = search_node(root,x);
    auto b = search_node(root,y);
    cout<<lca(a,b)<<endl;
	return 0;

}
