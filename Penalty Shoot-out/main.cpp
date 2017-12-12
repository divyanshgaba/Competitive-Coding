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
	string s;
	while(cin>>s)
	{
	    //first 5
	    int a =0,b=0,kicks=0;
	    for(int i = 0;i<10;i++)
        {
            kicks++;
            if(i&1)
                b+=(s[i]-'0');
            else
                a+=(s[i]-'0');
            if(a!=b)
            {
                if(a>b+(5-(i+1)/2))
                    break;
                if(b>a+(5 - (i+2)/2))
                    break;
            }
        }
        if(a!=b)
        {
            if(a>b)
                cout<<"TEAM-A";
            else
                cout<<"TEAM-B";
            cout<<" "<<kicks<<endl;
            continue;
        }
        a=b=0;
        for(int i = 10;i<20;i+=2)
        {
            kicks+=2;
            a+=(s[i]-'0');
            b+=(s[i+1]-'0');
            if(a!=b)
                break;

        }
        if(a!=b)
        {
            if(a>b)
                cout<<"TEAM-A";
            else
                cout<<"TEAM-B";
            cout<<" "<<kicks<<endl;
        }
        else
            cout<<"TIE"<<endl;
	}
	return 0;

}
