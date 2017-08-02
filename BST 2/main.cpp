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
    struct node *left,*right;
};

node* child(int val)
{
    node* temp = new node;
    temp->val = val;
    temp->right = temp->left = NULL;
    return temp;
}

bool exist(node* root, int val)
{
    if(root == NULL)
        return false;
    if(root->val == val)
        return true;
    return exist(root->left,val)||exist(root->right, val);
}

bool AnsOn2(node* root, int k)
{
    if(root == NULL)
        return false;
    return exist(root->left, k - root->val)||exist(root->right,k-root->val)||AnsOn2(root->left,k)||AnsOn2(root->right,k);
}
int cnt = 0;
unordered_map<int,int> mp;
void load(node *root)
{
    if(root == NULL)
        return;
    mp[root->val] += 1;
    load(root->left),load(root->right);
}
bool AnsOn(node* root, int k)
{
    for(auto i:mp)
    {
        if(mp.count(k-i.F)>0 && (i.F !=k-i.F || mp[k-i.F]>1))
        {
            return true;
        }
    }
    return false;
}
bool AnsOn2n(node* root, int k)
{
    for(auto i = mp.begin();i!=mp.end();i++)
    {
        for(auto j = mp.begin();j!=mp.end();j++)
        {
            if(k - (*i).F == (*j).F && ((*i).F != (*j).F) || mp[(*i).F]>1)
                return true;
        }
    }
    return false;
}

int main()
{
	fast;
    node* root = child(50);
    root->left = child(20);
    root->right = child(20);
    load(root);
    cout<<AnsOn(root,40)<<" "<<AnsOn2n(root,40)<<endl;
	return 0;

}
