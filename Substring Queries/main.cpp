#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct mental {
	int len, link;
	map<char,int> next;
};
const int MAXLEN = 100001;
mental st[MAXLEN*2];
int sz, last;
inline void sain() {
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	st[0].next.clear();
	st[1].next.clear();
	++sz;
}
inline void sax (char c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
string lcs (string & s, string & t) {
	sain();
	for (int i=0; i<(int)s.length(); ++i)
		sax (s[i]);

	int v = 0,  l = 0,
		best = 0,  bestpos = 0;
	for (int i=0; i<(int)t.length(); ++i) {
		while (v && ! st[v].next.count(t[i])) {
			v = st[v].link;
			l = st[v].len;
		}
		if (st[v].next.count(t[i])) {
			v = st[v].next[t[i]];
			++l;
		}
		if (l > best)
			best = l,  bestpos = i;
	}
	return (t.substr (bestpos-best+1, best));
}
int x,y;
int main()
{
    int n,q;
    vector<pair<string,int> > vs;
    cin>>n>>q;
    for(int i =0;i<n;i++)
    {
        string s;
        cin>>s;
        vs.push_back(make_pair(s,s.size()));
    }
    for(int i =0;i<q;i++)
    {

        cin>>x>>y;
        //memset(st,0,sizeof(st));
        for(int i =0;i<2*MAXLEN;i++            st[i].next.clear();
        if(vs[x].second < vs[y].second)
            swap(x,y);
        string ans = lcs(vs[x].first,vs[y].first);
        if(ans.size()>0)
            cout<<ans.size();
        else
            cout<<0;
        cout<<endl;
    }
    return 0;
}
