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
int m;
int arr[21];
int cnt = 0;
template<typename T> T gcd(T a, T b) {
	return (b ? __gcd(a,b) : a);
}

bool buf[21];

int main()
{
	fast;
	cin>>m;
	int zer = 0;
	for(int i = 0;i<m;i++)
    {
        cin>>arr[i];
        if(!arr[i])
            zer++;
        buf[arr[i]]=true;
    }
    vector<int> v(zer);
    for(int i = 0;i<zer;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(!buf[j])
            {
                v[i]=j;
                buf[j]=true;
                break;
            }
        }
    }
    vector<int> ans(m,0);
    do{
        int j=0;
        bool valid = true;
        for(int i = 0;i<m;i++)
        {
            if(arr[i])
                ans[i]=arr[i];
            else
                ans[i]=v[j++];
            if(i!=0)
            {
                if(gcd(ans[i],ans[i-1])>1)
                {
                    valid = false;
                    break;
                }
            }
        }
        if(valid)
            cnt++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<cnt<<endl;
	return 0;

}
