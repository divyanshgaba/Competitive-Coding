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
	int n,k;
	cin>>n>>k;
	if(k&1)
    {
        if(k==n-2)
        {
            cout<<"YES\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";
            cout<<".";
            for(int i = 0;i<k;i++)
                cout<<"#";
            cout<<".";
            cout<<"\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";

        }
        else if(k>=5)
        {
            cout<<"YES\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";

            cout<<".";
            for(int i = 0;i<min(n-2,k-2);i++)
                cout<<"#";
            for(int i = min(n-2,k-2);i<n-1;i++)
                cout<<".";
            cout<<"\n";
            int h = k - 2 - min(k-2,n-2);
            for(int i = 0;i<n;i++)
            {
                if(i==1||i == (min(n-2,k-2)))
                    cout<<"#";
                else if(i&&h>0)
                    cout<<"#",h--;
                else
                    cout<<".";
            }
            cout<<"\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";
        }
        else if(k==1)
        {
            cout<<"NO\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";

            for(int i = 0;i<n;i++)
            {
                if(i==n/2)
                    cout<<"#";
                else
                    cout<<".";
            }

            cout<<"\n";
            for(int i = 0;i<n;i++)
                cout<<".";

            cout<<"\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";
        }
        else if(k==3)
        {
            cout<<"YES\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";

            for(int i = 0;i<n;i++)
            {
                if(i==1||i==3)
                    cout<<"#";
                else
                    cout<<".";
            }

            cout<<"\n";
            for(int i = 0;i<n;i++)
            {
                if(i==2)
                    cout<<"#";
                else
                    cout<<".";
            }
            cout<<"\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";
        }
    }
    else
    {
        if(k<=2*(n-2))
        {
            cout<<"YES\n";
            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";
            cout<<".";
            for(int i = 0;i<k/2;i++)
                cout<<"#";
            for(int i = k/2+1;i<n;i++)
                cout<<".";
            cout<<"\n";
            cout<<".";
            for(int i = 0;i<k/2;i++)
                cout<<"#";
            for(int i = k/2+1;i<n;i++)
                cout<<".";
            cout<<"\n";

            for(int i = 0;i<n;i++)
                cout<<".";
            cout<<"\n";
        }
        else{
            cout<<"NO\n";
        }
    }
	return 0;

}
