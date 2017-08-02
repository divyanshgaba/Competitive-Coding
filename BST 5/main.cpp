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
    struct node* left, *right, *parent;
};

int cnt = 0;
node* child(int val, node *prev)
{
    cnt++;
    node *temp = new node;
    temp->val = val;
    temp->left = temp->right = NULL;
    temp->parent = prev;
    return temp;
}

node* insert(node* root, int val, node* prev)
{
    if(root == NULL)
       return child(val, prev);
    if(root->left!)
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
            root = insert_ele(root,v);
        else
            insert_ele(root,v);
    }
    inorder(root);
    cout<<endl;

	return 0;

}
