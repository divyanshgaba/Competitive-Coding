#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		int a;
		int xorA = 0;
		for(int i = 0;i<n;i++)
            cin>>a,xorA ^=(a<<1);
        cout<<xorA<<endl;
    }
	return 0;
}
