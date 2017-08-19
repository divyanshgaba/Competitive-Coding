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

bool palindrome(int a[],int n)
{
    for(int i = 0;i<n/2;i++)
    {
        if(a[i] != a[n-i-1])
            return false;
    }
    return true;
}


int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;i++)
            cin>>a[i];
        bool rainbow = true, seven = false;
        int c = 1;
        for(int i = 0;i<n&&rainbow;i++)
        {
            if(c == 7)
                seven = true;
            if(!seven)
            {
                if(c == a[i])
                    continue;
                if(c+1 != a[i])
                    rainbow = false;
                else
                    c+=1;
            }
            else
            {
                if(c==a[i])
                    continue;
                if(c-1 != a[i])
                    rainbow = false;
                else
                    c-=1;
            }
        }
        bool pal = palindrome(a,n);
        if(rainbow && seven&& pal)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
	return 0;

}
