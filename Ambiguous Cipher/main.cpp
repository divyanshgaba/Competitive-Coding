/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); fin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

unordered_map<char,int> mp;
void init()
{
    for(int i = 0;i<26;i++)
        mp['A'+i] = i;
}

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
	fast;
	int test=1;
	fin>>test;
	init();
	for(int t = 1;t<=test;t++)
    {
		string w,a;
		fin>>w;
		if(w.length() %2 !=0)
        {
            a = "AMBIGUOUS";
        }
        else
        {
            a = w;
            a[1] = w[0];
            a[w.length()-2] = w[w.length()-1];
            for(int i = 3;i<a.length();i+=2)
            {
                a[i] = (w[i-1] - a[i-2] +26)%26 + 65;
            }
            for(int i = a.length()-4;i>=0;i-=2)
            {
                a[i] = (w[i+1] - a[i+2] +26)%26 + 65;
            }
        }
		fout<<"Case #"<<t<<": "<<a<<endl;
    }
	return 0;

}
