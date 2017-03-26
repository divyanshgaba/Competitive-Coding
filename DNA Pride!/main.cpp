#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int flag =0;
        for(int i =0;i<n;i++)
        {
            switch(s[i])
            {
            case 'A':
                s[i]='T';
                break;
            case 'T':
                s[i]='A';
                break;
            case 'G':
                s[i]='C';
                break;
            case 'C':
                s[i]='G';
                break;
            default:
                flag=1;
                break;

            }
            if(flag==1)
                break;
        }
        if(flag ==0)
            cout<<s<<"\n";
        else
            cout<<"Error RNA nucleobases found!\n";
    }
	return 0;

}
