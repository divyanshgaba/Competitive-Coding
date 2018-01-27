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

struct TreapNode
{
    int  priority;
    string a;
    ll x;
    ll child;
    TreapNode *left, *right;
};
TreapNode *rightRotate(TreapNode *y)
{
    TreapNode *x = y->left,  *T2 = x->right;
    x->right = y;
    y->left = T2;
    x->child+=1;
    y->child-=1;
    return x;
}
TreapNode *leftRotate(TreapNode *x)
{
    TreapNode *y = x->right, *T2 = y->left;

    y->left = x;
    x->right = T2;
    y->child+=1;
    x->child-=1;

    return y;
}

TreapNode* newNode(string a, ll x)
{
    TreapNode* temp = new TreapNode;
    temp->a = a;
    temp->x = x;
    temp->child = 1;
    temp->priority = rand()%100;
    temp->left = temp->right = NULL;
    return temp;
}
void update(TreapNode* root,TreapNode* cur, string a,ll x)
{
    if(root->a == a)
    {
        return;
    }
    if(root->x <= x)
    {
        cur->left = root->left;
        if(root->right == NULL)
        {
            cur->right = newNode(a,x);
            return;
        }
        else
        {
            cur->right = newNode(root->right->a,root->right->x);

        }
    }
}
TreapNode* insert(TreapNode* root, int key)
{
    if (!root)
        return newNode(key);

    // If key is smaller than root
    if (key <= root->key)
    {
        // Insert in left subtree
        root->left = insert(root->left, key);

        // Fix Heap property if it is violated
        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else  // If key is greater
    {
        // Insert in right subtree
        root->right = insert(root->right, key);

        // Fix Heap property if it is violated
        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {

    }
	return 0;

}
