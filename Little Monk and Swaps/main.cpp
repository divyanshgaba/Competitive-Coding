#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for(int i =0;i<n;i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


struct node
{
    int ele;
    struct node* left,*right;
    node(int x)
    {
        left =right = NULL;
        ele = x;
    }
};
int n;
int a[100001];
struct node *createTree(int i)
{
    if(i>=n)
    {
        return NULL;
    }
    struct node *root = new node(a[i]);
    root->left = createTree(2*i+1);
    root->right= createTree(2*i+2);
    return root;
}
vi v;
void inorder(struct node*root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    //cout<<root->ele<<" ";
    v.PB(root->ele);
    inorder(root->right);
}
int main()
{
	fast;
	cin>>n;
	pi arr[n];
	FOR(i,n)
	{
	    cin>>a[i];

	}
	struct node *root = createTree(0);
    inorder(root);
    FOR(i,n)
    {
	    arr[i].F=v[i];
	    arr[i].S=i;

	}
    sort(arr,arr+n);
    vector<bool> vis(n,false);
    int ans =0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]||arr[i].S==i)
            continue;
        int siz =0;
        int j =i;
        while(!vis[j])
        {
            vis[j]=true;
            j=arr[j].S;
            siz++;
        }
        ans+=(siz-1);
    }
    cout<<ans;
	return 0;

}
