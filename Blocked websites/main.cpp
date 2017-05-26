#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define INT(c) c -'a'

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

vector<string> a,m;

struct node
{
    struct node *child[26];
    int freq;

};
struct node * newNode()
{
    struct node* temp = new node;
    temp->freq =1;
    for(int i =0;i<26;i++)
        temp->child[i] =NULL;
    return temp;

}
void insert(struct node* root, string str)
{
    int len = str.length();
    struct node* cursor = root;
    for (int level = 0; level<len; level++)
    {
        int index = INT(str[level]);

        // Create a new child if not exist already
        if (!cursor->child[index])
            cursor->child[index] = newNode();
        else
           (cursor->child[index]->freq)++;

        // Move to the child
        cursor = cursor->child[index];
    }
}
int getp(struct node* root, string s)
{
    int len = s.length();
    struct node* cursor = root;
    for(int i =0;i<len;i++)
    {
        int in = INT(s[i]);
        if(!cursor->child[in])
        {
            return i+1;
        }
        cursor=cursor->child[in];
    }
    return -1;
}
int main()
{
	fast;
	int n;
	cin>>n;
	node* root = newNode();
	node* ans = newNode();
	for(int i =0;i<n;i++)
    {
        char c;
        string s;
        cin>>c>>s;
        if(c=='+')
            insert(root,s);
        else
            m.PB(s);
    }
    //priority_queue<string, vector<string>, greater<string> > q;
    set<string> st;
    for(auto i:m)
    {
        int in = getp(root,i);
        if(in ==-1)
        {
            cout<<-1<<endl;
            return 0;
        }
        st.insert(st.begin(),i.substr(0,in));
    }
    cout<<st.size()<<endl;
    for(auto i:st)
        cout<<i<<endl;
	return 0;

}
