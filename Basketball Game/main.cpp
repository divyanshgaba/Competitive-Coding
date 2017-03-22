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
	fast;
	int test;
    cin>>test;
    while(test--)
    {
        pi hoop;
        cin>>hoop.F>>hoop.S;
        pi car;
        int sc;
        cin>>car.F>>car.S>>sc;
        pi pla[5];
        int pls[5];
        for(int i =0;i<5;i++)
        {
            cin>>pla[i].F>>pla[i].S>>pls[i];
        }
        bool poss = true;
        for(int i =0;i<5&&poss;i++)
        {
            pi ht = hoop;
            pi ct = car;
            double dx = ht.F - ct.F;
            double dy = ht.S -ct.S;
            double dis = sqrt(dx*dx +dy*dy);
            double time = ceil(dis/sc-1);
            double r = pls[i]*time;
            ht.F -= pla[i].F;
            ht.S -= pla[i].S;
            ct.F -= pla[i].F;
            ct.S -= pla[i].S;
            double del;
            if(ht.F - ct.F !=0)
            {
                double m = (ht.S - ct.S)/(ht.F - ct.F);
                double a =1;
                double b = -m;
                double c = -1*(m*ct.F + ht.F);
                del = r*r*(a*a+b*b) - c*c;
            }
            else
            {
                double a =1;
                double b = 0;
                double c = -1*(ht.F);
                del = r*r*(a*a+b*b) - c*c;
            }
            if(del>=0)
                poss = false;

        }
        if(poss)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
	return 0;

}
