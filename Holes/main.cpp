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
const int rtN = 350;
const int ZERO = -11111111;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n];
	for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    pi jump[n];
    for(int i = 0;i<n;i++)
    {
        int prev = i;
        int ind = i;
        jump[i]={0,-1};
        while(ind/rtN == i/rtN&&ind<n)
        {

            prev = ind;
            jump[i].F++;
            ind+=a[ind];
            //cout<<i<<" "<<ind<<endl;
        }
        if(ind<n)
            jump[i].S=ind;
        else
        {
            if(prev == 0)
                jump[i].S=ZERO;
            else
                jump[i].S=-prev;
        }
    }
    while(m--)
    {
        int t;
        scanf("%d",&t);
        if(t==0)
        {
            int ai,b;
            scanf("%d %d",&ai,&b);
            ai--;
            a[ai]=b;
            int i = 0;
            while((ai/rtN)*rtN + i<n&&i<rtN)
            {

                int ind = (ai/rtN)*rtN+i;
                int prev = ind;
                jump[ind]={0,-1};
                while((ind/rtN == ((ai/rtN)*rtN+i)/rtN)&&ind<n)
                {
                    prev = ind;
                    jump[(ai/rtN)*rtN+i].F++;
                    ind+=a[ind];
                }
                if(ind<n)
                    jump[(ai/rtN)*rtN+i].S = ind;
                else
                {
                    if(prev == 0)
                        jump[(ai/rtN)*rtN+i].S=ZERO;
                    else
                        jump[(ai/rtN)*rtN+i].S=-prev;
                }
                i++;
            }
        }
        else
        {
            int ai;
            scanf("%d",&ai);
            int ans = 0;
            int ind = ai-1;
            while(ind>=0)
            {
                ans += jump[ind].F;
                ind = jump[ind].S;
            }
            if(ind==ZERO)
                printf("1 ");
            else
                printf("%d ",-ind+1);
            printf("%d\n",ans);
        }
        //for(int i = 0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
    }

	return 0;

}
