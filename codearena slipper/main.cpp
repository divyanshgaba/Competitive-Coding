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
typedef pair<string,string> ps;


int toint(string s)
{
    //pt a;
    cout<<s<<endl;
    //a.F = atoi((s.substr(0,2).c_str()));
    //a.S = atoi((s.substr(2,2).c_str()));
    //return a.F *60 + a.S;

}

int main()
{
	fast;
	int test;
	cin>>test;
	for(int k =1;k<=test;k++)
    {
        int n;
        cin>>n;
        pi xy,pq,ab;
        scanf("%d:%d",&xy.F,&xy.S);
        //cout<<a.F<<" "<<a.S;
        int xyt = xy.F*60 + xy.S;
        scanf("%d:%d",&pq.F,&pq.S);
        int pqt = pq.F*60 + pq.S;

        scanf("%d:%d",&ab.F,&ab.S);
        int r,s;
        cin>>r>>s;
        int abt = ab.F*60 + ab.S;
        int flag =0;
        int go = max(abt,pqt);
        int ans =0;
        for(int i =0;i<n;i++)
        {
            pi hm1,hm2;
            scanf("%d:%d",&hm1.F,&hm1.S);
            int hmt1 = hm1.F*60 + hm1.S;
            scanf("%d:%d",&hm2.F,&hm2.S);
            int hmt2 = hm1.F*60 + hm2.S;
            if(go + r+s+r >=hmt1)
                continue;
            if(flag==0&&hmt2+r+r+s <=xyt)
            {
                flag =1;
                ans = i+1;
            }
        }

        cout<<"Case "<<k<<": "<<ans<<endl;

    }
	return 0;

}
