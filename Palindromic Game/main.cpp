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

int main()
{
    fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		string s;
		cin>>s;
		string t;
		cin>>t;
		unordered_map<char, int> freqS, freqT;
		for(auto i:s)
            freqS[i]++;
        for(auto i:t)
            freqT[i]++;
		set<char> S(s.begin(),s.end()),T(t.begin(),t.end());
		vector<char> vs(30),vt(30);
		auto it = set_difference(S.begin(),S.end(),T.begin(),T.end(),vs.begin());
		vs.resize(it-vs.begin());
		it = set_difference(T.begin(),T.end(),S.begin(),S.end(),vt.begin());
		vt.resize(it-vt.begin());
        //A has unique occurring atleast twice
        if(vs.size() != 0)
        {
            bool A = false;
            for(auto i:vs)
                if(freqS[i] > 1)
                {
                    A = true;
                    break;
                }
            if(A)
            {
                cout<<"A\n";
                continue;
            }
        }
        // A has unique but B doesn't
        if(vs.size() !=0 && vt.size() == 0)
        {
            cout<<"A\n";
            continue;
        }
        cout<<"B\n";
    }
	return 0;

}
