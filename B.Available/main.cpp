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
const int INF = 0x3f3f3f3f;
int prices[301][301];
int minstay[301][301];
int maxstay[301][301];
int tree[301][1000];
int lazy[301][1000];
vector<pair<int,pi> >p[301];

struct Interval
{
    int low, high;
};

// Structure to represent a node in Interval Search Tree
struct ITNode
{
    Interval *i;  // 'i' could also be a normal variable
    int max;
    ITNode *left, *right;
};

// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
};

// A utility function to insert a new Interval Search Tree Node
// This is similar to BST Insert.  Here the low value of interval
// is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i)
{
    // Base case: Tree is empty, new node becomes root
    if (root == NULL)
        return newNode(i);

    // Get low value of interval at root
    int l = root->i->low;

    // If root's low value is smaller, then new interval goes to
    // left subtree
    if (i.low < l)
        root->left = insert(root->left, i);

    // Else, new node goes to right subtree.
    else
        root->right = insert(root->right, i);

    // Update the max value of this ancestor if needed
    if (root->max < i.high)
        root->max = i.high;

    return root;
}

// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}

// The main function that searches a given interval i in a given
// Interval Tree.
Interval *overlapSearch(ITNode *root, Interval i)
{
    // Base Case, tree is empty
    if (root == NULL) return NULL;

    // If given interval overlaps with root
    if (doOVerlap(*(root->i), i))
        return root->i;

    // If left child of root is present and max of left child is
    // greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);

    // Else interval can only overlap with right subtree
    return overlapSearch(root->right, i);
}
int main()
{
	fast;
	int n,m,q;
	cin>>n>>m>>q;
	for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>prices[i][j];
            if(prices[i][j]==0)
                prices[i][j]=INF;
        }
    }
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>minstay[i][j];
        }
    }
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>maxstay[i][j];
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            Interval ints;
            ints.low = minstay[j][i];
            ints.high=maxstay[j][i];

        }
    }
    memset(tree,INF,sizeof(tree));
    for(int i =0;i<n;i++)
    {
        sort(p[i].begin(),p[i].end(),greater<pair<int,pi> >());
        for(int j =0;j<p[i].size();j++)
        {

        }
    }


    for(int i =0;i<q;i++)
    {
        int c,l;
        cin>>c>>l;
        c--;
        int cost =0;
        int flag =0;
        for(int j = c;j<c+l;j++)
        {

        }
        cout<<endl;
        if(cost<INF)
        cout<<cost<<endl;
        else
            cout<<-1<<endl;
    }
    /*for(int i =0;i<n;i++)
    {
        for(auto j:p[i])
            cout<<j.F<<" ("<<j.S.F<<" "<<j.S.S<<") - ";
        cout<<endl;
    }*/

	return 0;

}
