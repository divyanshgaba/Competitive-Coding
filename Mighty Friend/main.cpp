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
		int n,k;
		cin>>n>>k;
		vector<int> mot, tom;
		long long smot=0,stom=0;
		for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            if(i&1)
                tom.PB(x),stom+=x;
            else
                mot.PB(x),smot+=x;
        }
        sort(tom.begin(),tom.end());
        sort(mot.begin(),mot.end());
        for(int i = 0;i<min(k,int(tom.size()));i++)
        {
            if(tom[i] < mot[mot.size()-i-1])
                smot += (tom[i] - mot[mot.size()-i-1]),stom -= (tom[i] - mot[mot.size()-i-1]);
        }
        assert(smot>0 && stom>=0);
        //cout<<stom <<" "<<smot<<endl;
        if(stom>smot)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
	return 0;

}
