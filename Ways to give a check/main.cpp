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

bool valid(int x,int y)
{
    if(x<0||y<0||x>7||y>7)
        return false;
    return true;
}

bool bishop(char c[8][8],pi blackK,pi bis)
{
    int x[]={1,-1,1,-1};
    int y[]={1,1,-1,-1};
    for(int i = 0;i<4;i++)
    {
        pi t = bis;
        while(valid(t.F+x[i],t.S+y[i]))
        {
            cout<<t.F<<" "<<t.S<<endl;
            t.F+=x[i];
            t.S+=y[i];
            if(t.F==blackK.F&&t.S==blackK.S)
                return true;
            if(c[t.F][t.S]!='#')
                break;
        }
    }
    return false;
}
bool king(char c[8][8],pi blackK,pi bis)
{
    int x[]={0,0,1,-1,-1,1,-1,1};
    int y[]={1,-1,0,0,-1,1,1,-1};
    for(int i = 0;i<8;i++)
    {
        pi t = bis;
        if(valid(t.F+x[i],t.S+y[i]))
        {
            t.F+=x[i];
            t.S+=y[i];
            if(t.F==blackK.F&&t.S==blackK.S)
                return true;

        }
    }
    return false;
}
bool rook(char c[8][8],pi blackK,pi roo)
{
    int x[]={0,0,1,-1};
    int y[]={1,-1,0,0};
    for(int i = 0;i<4;i++)
    {
        pi t = roo;
        while(valid(t.F+x[i],t.S+y[i]))
        {
            t.F+=x[i];
            t.S+=y[i];
            if(t.F==blackK.F&&t.S==blackK.S)
                return true;
            if(c[t.F][t.S]!='#')
                break;
        }
    }
    return false;
}
bool knight(char c[8][8],pi blackK,pi kni)
{
    int x[]={1,1,-1,-1,2,2,-2,-2};
    int y[]={2,-2,2,-2,1,-1,1,-1};
    for(int i = 0;i<8;i++)
    {
        if(blackK.F == kni.F+x[i] && blackK.S == kni.S+y[i])
            return true;
    }
    return false;
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		char c[8][8];
		for(int i = 0;i<8;i++)
            for(int j = 0;j<8;j++)
                cin>>c[i][j];
        int check = false;
        pi blackK;
        vector<pi> v;
        for(int i = 0;i<8;i++)
        {
            for(int j = 0;j<8;j++)
            {
                if(c[i][j]=='k')
                    blackK = {i,j};
                if(c[i][j]!='#')
                    v.PB({i,j});
            }
        }
        for(auto i:v)
        {
            //cout<<i.F<<" "<<i.S<<endl;
            if(c[i.F][i.S]=='P')
                continue;
            if(c[i.F][i.S] == 'Q')
            {
                if(bishop(c,blackK,{i.F,i.S})||rook(c,blackK,{i.F,i.S}))
                    check = true;
            }
            //king
            if(c[i.F][i.S] == 'K')
            {
                if(king(c,blackK,{i.F,i.S}))
                    check = true;
            }
            if(c[i.F][i.S] == 'R')
            {
                if(rook(c,blackK,{i.F,i.S}))
                    check = true;
            }
            if(c[i.F][i.S] == 'B')
            {
                if(bishop(c,blackK,{i.F,i.S}))
                    check = true;
            }
            //knight
            if(c[i.F][i.S] == 'N')
            {
                if(knight(c,blackK,{i.F,i.S}))
                    check = true;
            }
        }
        if(check)
        {
            cout<<4<<endl;
            continue;
        }
        int way=0;
        for(auto i:v)
        {
            if(c[i.F][i.S]!='P')
                continue;
            if(i.F!=1)
                continue;
            i.F-=1;
            if(bishop(c,blackK,{i.F,i.S})||rook(c,blackK,{i.F,i.S}))
                    way++;
            if(rook(c,blackK,{i.F,i.S}))
                    way++;
            if(knight(c,blackK,{i.F,i.S}))
                    way++;
            if(bishop(c,blackK,{i.F,i.S}))
                    way++;
            cout<<i.F<<" "<<i.S<<endl;
        }
        cout<<way<<endl;
    }
	return 0;

}
