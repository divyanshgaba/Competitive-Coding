#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i =0;i<n;i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct node
{
    struct node *left,*right;
    int ele;
    node()
    {
        left = NULL;
        right = NULL;
    }
    node(int x)
    {
        ele = x;
        left =NULL;
        right = NULL;
    }
};


struct node* insert(struct node* root,int data)
{
    if(root==NULL)
        return new node(data);
    if(data<=root->ele)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;

}
struct node* find_parent(struct node*root,int a,int b)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->ele == a || root->ele == b)
        return root;
    struct node* left = find_parent(root->left,a,b);
    struct node *right = find_parent(root->right,a,b);
    if(left!=NULL && right!= NULL)
        return root;
    if(left!=NULL)
        return left;
    return right;
}
int find_max(struct node*root,int a,int b)
{
    struct node*temp = find_parent(root,a,b);
    int ans = b;
    while(temp->ele != b)
    {
        ans =max(ans,temp->ele);
        if(temp->ele < b)
            temp= temp->right;
        else
            temp = temp->left;

    }
    return ans;
}
int main()
{
	fast;
	int n;
	cin>>n;
	struct node *root =NULL;
	FOR(i,n)
	{
	    int x;
	    cin>>x;
	    root = insert(root,x);
	}
	int a,b;
	cin>>a>>b;
	if(a>b)
        swap(a,b);
	cout<<find_max(root,a,b)<<"\n";
	return 0;

}
