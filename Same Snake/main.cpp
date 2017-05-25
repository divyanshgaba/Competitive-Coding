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

struct point
{
    ll x, y;
    point()
    {
        x=y=0;
    }
    bool operator==(point a)
    {
        return x==a.x&&y==a.y;
    }
    bool operator>(point a)
    {
        if(x==a.x)
            return y>a.y;
        return x>a.x;
    }
};

bool answer(point a,point b,point c,point d)
{
    if(a==c || b==c)
        return true;
    if(a==d || b==d)
        return true;
    if(a.y == b.y && c.y == d.y && a.y == c.y)
    {

        if( (a.x<=c.x && b.x>=c.x) || (a.x<=d.x&&b.x>=d.x))
            return true;
        if( (c.x<=a.x && d.x>=a.x)  || (c.x<=b.x && d.x>=b.x))
            return true;
        if( (a.x>=c.x && b.x<=c.x) || (a.x>=d.x&&b.x<=d.x))
            return true;
        if( (c.x>=a.x && d.x<=a.x)  || (c.x>=b.x && d.x<=b.x))
            return true;
    }
    if(a.x == b.x && c.x == d.x && a.x == b.x)
    {

        if( (a.y<=c.y && b.y>=c.y) || (a.y<=d.y&&b.y>=d.y))
            return true;
        if((c.y<=a.y && d.y>=a.y) || (c.y<=b.y && d.y>=b.y))
            return true;
        if( (a.y>=c.y && b.y<=c.y) || (a.y>=d.y&&b.y<=d.y))
            return true;
        if((c.y>=a.y && d.y<=a.y) || (c.y>=b.y && d.y<=b.y))
            return true;
    }
    return false;

}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        point a,b,c,d;
        cin>>a.x>>a.y>>b.x>>b.y;
        cin>>c.x>>c.y>>d.x>>d.y;
        if(answer(a,b,c,d))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
	return 0;

}
