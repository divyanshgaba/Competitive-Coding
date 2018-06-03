#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define PB push_back
using namespace std;
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
		int n,q;
		cin>>n>>q;
        vector<int> a(n),b(n);
        unordered_map<int,int> m;
        for(int i = 0;i<n;i++)
            cin>>a[i],b[i]=a[i],m[a[i]]=i;
        sort(b.begin(),b.end());
        while(q--)
        {
            int x;
            cin>>x;
            int low = 0, high = n-1;
            int wrongL=0,wrongR=0;
            int corrL=0,corrR=0;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(a[mid] == x)
                    break;
                else if(a[mid] < x)
                {
                    if(m[x] > mid)
                        low = mid + 1,corrL++;
                    else
                        high = mid - 1,wrongR++;
                }
                else
                {
                    if(m[x] < mid)
                        high = mid - 1,corrR++;
                    else
                        low = mid + 1,wrongL++;
                }
            }
            int ans = max(wrongL,wrongR);
            bool poss = ((wrongR+corrR) <= (b.end() - upper_bound(b.begin(),b.end(),x))) && ((wrongL+corrL) <= (lower_bound(b.begin(),b.end(),x) - b.begin()));
            cout<<(poss?ans:-1)<<endl;
        }
    }
	return 0;

}
