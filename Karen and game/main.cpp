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
int g[101][101];

vector<pi> row,col;
int n,m;
int min_row[101],min_col[101];
void min_row_calc()
{
    for(int i =0;i<n;i++)
    {
        int res = 501;
        for(int j = 0;j<m;j++)
            res = min(res,g[i][j]);
        min_row[i]= res;
    }
}
void min_col_calc()
{
    for(int j =0;j<m;j++)
    {
        int res = 501;
        for(int i = 0;i<n;i++)
            res = min(res,g[i][j]);
        min_col[j] = res;
    }
}
inline int min_row_fun(int i)
{
    return min_row[i];
}
inline int min_col_fun(int j)
{
    return min_col[j];
}
void sub_row(int i,int j,int x)
{

    min_row[i]-=x;
    for(int j = 0;j<m;j++)
    {
        g[i][j]-=x;
        min_col[j] = min(min_col[j],g[i][j]);
    }
}
void sub_col(int i,int j,int x)
{
    min_col[j] -=x;
    for(int i = 0;i<n;i++)
    {
        g[i][j]-=x;
        min_row[i] = min(min_row[i],g[i][j]) ;
    }
}
void print_grid()
{
    for(int i =0;i<n;i++,cout<<endl)
        for(int j = 0;j<m;j++)
            cout<<g[i][j]<<" ";
}

int main()
{
	fast;
	cin>>n>>m;
	for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>g[i][j];
    bool ans = true;
    min_row_calc(),min_col_calc();
    int strokes = 0;
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(min_row[i] > min_col[j])
            {
                int r = min_row_fun(i);
                if(r > 0)
                {
                    sub_row(i,j,r);
                    row.PB(MP(i,r));
                    strokes+=r;
                }
                int c = min_col_fun(j);
                if(c > 0)
                {
                    sub_col(i,j,c);
                    col.PB(MP(j,c));
                    strokes+=c;
                }
            }
            else
            {
                int c = min_col_fun(j);
                if(c > 0)
                {
                    sub_col(i,j,c);
                    col.PB(MP(j,c));
                    strokes+=c;
                }
                int r = min_row_fun(i);
                if(r > 0)
                {
                    sub_row(i,j,r);
                    row.PB(MP(i,r));
                    strokes+=r;
                }
            }
        }
    }
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            if(g[i][j]!=0)
                ans = false;
    //print_grid();
    if(ans)
    {
        cout<<strokes<<endl;
        for(auto i:row)
        {
            while(i.S--)
                cout<<"row "<<i.F+1<<endl;
        }
        for(auto i:col)
        {
            while(i.S--)
                cout<<"col "<<i.F+1<<endl;
        }
    }
    else
        cout<<-1<<endl;


	return 0;

}
