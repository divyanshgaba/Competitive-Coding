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
};

struct node* child(int val)
{
    node *temp = new node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert_ele(struct node* root, int val)
{
    if(root == NULL)
    {
        return child(val);
    }
    if(val<=root->val)
        root->left = insert_ele(root->left, val);
    else
        root->right = insert_ele(root->right, val);
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
void duplicate(node* root)
{
    if(root == NULL)
        return;

    node* temp = root->left;
    root->left = child(root->val);
    root->left->left = temp;

    duplicate(root->right),duplicate(temp);
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
	duplicate(root);
	inorder(root);
	cout<<endl;
	return 0;

}
