#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct TrieNode
{
    struct TrieNode *children[26];
    int count;
    vector<int> r;
    bool isLeaf;
};
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    pNode->count =0;
    if (pNode)
    {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}
void insert(struct TrieNode *root, const char *key,int i)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl->count+=1;
        pCrawl->r.push_back(i);
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isLeaf = true;
}
int search(struct TrieNode *root, const char *key,int l, int r)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        pCrawl = pCrawl->children[index];
    }
    int cnt=0;
    for(auto it:pCrawl->r)
    {
        if(it>=l && it<=r)
            cnt++;
    }
    return cnt;
}
void dele(struct TrieNode* root,const char *key,int i)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        pCrawl->count-=1;
        pCrawl->r.erase(remove(pCrawl->r.begin(),pCrawl->r.end(),i),pCrawl->r.end());
        // if(pCrawl->count == 0)            pCrawl->isLeaf =false;
        pCrawl = pCrawl->children[index];
    }
}
int main()
{
	fast;
	int n,q;
	cin>>n>>q;
	vector<string> a;
    struct TrieNode *root = getNode();
	for(int i =0;i<n;i++)
    {
        string s;
        cin>>s;
        a.PB(s);
        insert(root,s.c_str(),i);
    }

    for(int i =0;i<q;i++)
    {
        int t;
        cin>>t;
        if(t==2)
        {
            int j;
            string x;
            cin>>j>>x;
            dele(root,a[j-1].c_str(),j-1);
            insert(root,x.c_str(),j-1);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            string x;
            cin>>x;
            cout<<search(root,x.c_str(),l-1,r-1)<<endl;
        }
    }

	return 0;

}
