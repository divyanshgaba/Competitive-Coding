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
    char c[9][9];
    for(int i = 0;i<9;i++)
    {
        for(int j = 0;j<9;j++)
            cin>>c[i][j];
    }
    int n,m;
    cin>>n>>m;
    n--,m--;
    int x = n%3, y = m%3;
    bool t = false;
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            if(c[x*3+i][y*3+j]=='.')
                t = true,c[x*3+i][y*3+j]='!';
        }
    }
    if(t)
    {
        for(int i = 0;i<9;i++)
        {
            if(i!=0&&i%3==0)
                cout<<endl;
            for(int j = 0;j<9;j++)
            {
                if(j%3 == 0 && j!=0)
                    cout<<" ";
                cout<<c[i][j];
            }
            cout<<endl;
        }
    }
    else
    {
        for(int i = 0;i<9;i++)
        {
            if(i!=0&&i%3==0)
                cout<<endl;
            for(int j = 0;j<9;j++)
            {
                if(j%3 == 0 && j!=0)
                    cout<<" ";
                if(c[i][j]=='.')
                    cout<<"!";
                else
                    cout<<c[i][j];
            }
            cout<<endl;
        }
    }
	return 0;

}
