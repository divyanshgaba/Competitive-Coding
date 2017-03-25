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

struct node
{
    int val;
    struct node*left,*right;
};

struct node* newNode(int x)
{
    struct node* node = new struct node;
    node->val = x;
    node->right=node->left = NULL;
    return node;
}

struct node* bst_insert(int x, struct node* root)
{
    if(root == NULL)
        return newNode(x);
    if(root->val <x)
        root->right = bst_insert(x,root->right);
    else
        root->left = bst_insert(x,root->left);
    return root;
}
int height(struct node *root)
{
    if(root == NULL)
        return 0;
    int ldepth = height(root->left);
    int rdepth = height(root->right);
    if(ldepth<rdepth)
        return rdepth+1;
    return ldepth+1;
}

int main()
{
	fast;
	int n;
    cin>>n;
    struct node* root=NULL;
    for(int i =0;i<n;i++)
    {
        int x;
        cin>>x;
        root = bst_insert(x,root);
    }
    cout<<height(root);
	return 0;

}
