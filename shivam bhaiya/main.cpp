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
    freopen("output.out","w",stdout);
	string s = "INSERT INTO seat(row,number) VALUES('%c',%d);\n";
	for(char a = 'A';a<='K';a++)
    {
        for(int i = 1;i<=12;i++)
        {
            printf(s.c_str(),a,i);
        }
    }

	return 0;

}
