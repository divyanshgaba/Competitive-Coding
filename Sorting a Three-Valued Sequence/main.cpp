/*
ID: divyans19
PROG: sort3
LANG: C++11
*/
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
    //ifstream fin("sort3.in");
    //ofstream fout("sort3.out");
	fast;
	int n;
	cin>>n;
	int a,b,c;
	a=b=c=0;
	int ar[n];
	for(int i =0;i<n;i++)
    {
        cin>>ar[i];
        if(ar[i] == 1)
            a++;
        else if(ar[i]==2)
            b++;
        else
            c++;
    }
    int a2=0,a3=0,b1=0,b3=0,c1=0,c2=0;
    for(int i =0;i<n;i++)
    {
        if(ar[i]==1)
        {
            if(i>=a)
            {
                if(i>=a+b)
                    c1++;
                else
                    b1++;
            }
        }
        if(ar[i] == 2)
        {
            if(i <a)
                a2++;
            if(i>= a+b)
                c2++;
        }
        if(ar[i]==3)
        {
            if(i<a+b)
            {
                if(i<a)
                    a3++;
                else
                    b3++;
            }
        }
    }
    int ans =0;
    int tmp = min(a2,b1);
    ans+=tmp;
    a2-=tmp;
    b1-=tmp;
    tmp = min(a3,c1);
    ans+=tmp;
    a3-=tmp;
    c1-=tmp;
    tmp = min(b3,c2);
    ans+=tmp;
    b3-=tmp;
    c2-=tmp;
    tmp =max(a2,max(a3,max(b1,max(b3,max(c2,c1)))));
    //cout<<tmp<<endl;
    ans+=2*tmp;
    //cout<<a2<<" "<<a3<<" "<<b1<<" "<<b3<<" "<<c1<<" "<<c2<<endl;
    cout<<ans<<endl;

	return 0;

}
