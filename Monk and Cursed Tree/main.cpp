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
int find_max(struct node*root,int b)
{
    int ans = 0;
    while(root->ele !=b)
    {
        ans = max(ans,root->ele);
        if(root->ele <b)
        {
            root =root->right;
        }
        else
        {
            root=root->left;
        }
    }
    ans = max(ans,root->ele);
    return ans;
}

int main()
{
	fast;
	int n;
	cin>>n;
	struct node *root =NULL;
	REP(i,0,n-1)
	{
	    int x;
	    cin>>x;
	    root = insert(root,x);
	}
	int a,b;
	cin>>a>>b;
	cout<<find_max(root,b)<<"\n";
	return 0;

}
