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

int x;

int main()
{
	fast;
	int p,x;
	cin>>p>>x;
	int time = 0;
	int a  = x;
	int i =1;
	while(p>0)
    {
        p=p-a;
        time++;
        if(p<=0)
            break;
        time+=i;
        a+=x;
        i++;

    }
    cout<<time<<endl;

	return 0;

}
