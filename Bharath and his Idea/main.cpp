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
        int n;
        cin>>n;
        //Input array for Length of bars at i'th block
        int a[n];
        for(int i =0;i<n;++i)
        {
            cin>>a[i];
        }

        int max_ahead =0;
        // for every i, we store the maximum bar ahead of i in this array
        int ahead[n];
        for(int i =n-1;i>=0;--i)
        {
            //is current max smaller than a[i]? if yes then a[i] is new max
            max_ahead =max(max_ahead,a[i]);

            //store info
            ahead[i]=max_ahead;
        }
        int ans =0;
        int max_so_far =0;
        for(int i =0;i<n;i++)
        {
            // in this variable we have maximum length of wall upto i
            max_so_far = max(max_so_far,a[i]);


            // water at i'th block will be min(max height upto i and max height ahead of i)
            // if there's is a wall at i'th block, we will need to subtract that amount as it has consumed the area available for water
            // NOTE: It is easy to see that this number will be non-negative
            int water_at_i = min(max_so_far,ahead[i]) - a[i];

            // add the result
            ans+=water_at_i;
        }
        //print the result
        cout<<ans<<endl;
    }
	return 0;

}
