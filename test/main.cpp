#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long long> VLL;
typedef set<string>::iterator LITER;

VS blocked, unblocked;

set<string> res;

const int maxn = 200119;
int charSize = 0;
int trie[26][maxn];

void insertTrie(string &s) {
	int c, i, _next = 0;
	for(i = 0; i < (int)s.size(); ++i) {
		c = s[i] - 'a';
		if(trie[c][_next] == 0)
            trie[c][_next] = ++charSize;
		_next = trie[c][_next];
	}
}

int searchTrie(string temp) {
	int c, i, _next = 0;
	for(i = 0; i < (int)temp.size(); ++i) {
		c = temp[i] - 'a';
		if(trie[c][_next] == 0)
            return i;
		_next = trie[c][_next];
	}
	return i;
}

void solve() {
    int n, i, k, flag = 0;
    string site;
    char decide;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> decide >> site;
        if(decide == '-') blocked.push_back(site);
        else if(decide == '+') unblocked.push_back(site);
    }
    sort(unblocked.begin(), unblocked.end());
    sort(blocked.begin(), blocked.end());

    for(i = 0; i < (int)unblocked.size(); i++)
        insertTrie(unblocked[i]);

    for(i = 0; i < (int)blocked.size(); i++) {
        k = searchTrie(blocked[i]);
        if(k < (int)blocked[i].length()) {
            site = blocked[i].substr(0, k + 1);
            res.insert(blocked[i].substr(0, k + 1));
        }
    }

	if(res.size()) {
		cout << res.size() << endl;
	    for(auto ite : res)
	    	cout << ite << endl;
	}
	else cout << "-1" << endl;

}

int main() {
    solve();
	return 0;
}
