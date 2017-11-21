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
struct node
{
    int r, minr,maxr,think;
    bool rated;
    int color;
    bool avail;
    node()
    {
        avail = true;
    }
};
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		vector<node> v;
		for(int i = 0;i<n;i++)
        {
            node a;
            cin>>a.r>>a.minr>>a.maxr>>a.think;
            string s;
            cin>>s;
            if(s=="rated")
                a.rated = true;
            else
                a.rated = false;
            cin>>s;
            if(s=="random")
            {
                a.color = 0;
            }
            else if(s=="white")
            {
                a.color=1;

            }
            else
                a.color=2;
            int ans = -1;
            for(int h = 0,k = v.size();h<k;h++)
            {
                node &j = v[h];
                if(!j.avail)
                    continue;
                if(j.think == a.think && a.rated == j.rated)
                {
                    if(j.r<=a.maxr && j.r>=a.minr && a.r<=j.maxr && a.r>=j.minr)
                    {
                        if((j.color == 0 && a.color == 0)||(a.color == 1 && j.color ==2) ||(a.color==2&&j.color==1))
                        {
                            ans = h+1;
                            a.avail = false;
                            j.avail = false;
                            break;
                        }

                    }
                }
            }
            v.PB(a);
            if(ans!=-1)
                cout<<ans<<endl;
            else
                cout<<"wait"<<endl;
        }



    }
	return 0;

}
