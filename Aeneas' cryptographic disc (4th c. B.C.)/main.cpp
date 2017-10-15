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
unordered_map<char,double> m;
const double PI = 3.141592653/180;
int main()
{
	fast;
	double r;
	cin>>r;
	for(int i = 0;i<26;i++)
    {
        char c;
        double angle;
        cin>>c>>angle;
        m[c]=angle;
    }
    double ans = 0;
    string s;
    char prev = '-';
    while(cin>>s)
    {
        for(auto i:s)
        {
            if(isalpha(i))
            {
                char t = toupper(i);
                if(prev=='-')
                    ans +=r,prev=t;
                else
                    ans += 2*(r*abs(sin(((abs(m[prev]-m[t])/2)*PI)))),prev=t;
            }
        }

    }
    cout<<int(ceil(ans))<<endl;
	return 0;

}
