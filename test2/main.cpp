#include <bits/stdc++.h>
using namespace std;

#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define forup(i,a,b) for(int i=(a);i<=(b);i++)
#define tcsolve() int tcs; cin >> tcs; forup(tc, 1, tcs) solve();

int bitsz(int n) {
	int i = 0;
	while (n) n >>= 1, i++;
	return i;
}

void solve() {
	int n, k, t, ans;
	cin >> n >> k;
	set<int, greater<int> > s, w;
	rep (i, n) {
		cin >> t;
		s.insert(t);
	}
	// Guassian Elimination!
	while (!s.empty()) {
		int m = *s.begin();
		s.erase(m);
		w.insert(m);
		int z = bitsz(m) - 1;
		tr (s, it) {
			t = *it;
			if (t>>z & 1) {
                    				s.insert(t^m);

				s.erase(t);
			}
		}
	}
	ans = k;
	tr (w, it)
		if ((ans^(*it)) > ans)
			ans ^= *it;
	cout << ans << endl;
}

int main () {
	std::ios::sync_with_stdio(false);
	tcsolve();
	return 0;
}
