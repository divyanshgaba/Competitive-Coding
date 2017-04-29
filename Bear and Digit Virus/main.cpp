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

bool notsame(string s,int n)
{

    for(int i =0;i<n;i++)
    {
        if(s[0] != s[i])
            return false;
    }
    return true;
}

int n50(string s,int n)
{
    int t =0;
    while(!notsame(s,n))
    {
        string k = s;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(s[i] - s[j] >= abs(i-j))
                {
                    k[j] = max(k[j],s[i]);
                }
            }
        }
        s = k;
        t++;
    }
    return t;
}
int n15(string s,int n)
{
    int t =0;
    while(!notsame(s,n))
    {
        string k = s;
        for(int i =0;i<n;i++)
        {
            for(int j =i-10;j<=i;j++)
            {
                if(s[i] - s[j] >= abs(i-j))
                {
                    k[j] = max(k[j],s[i]);
                }
            }
            for(int j =i;j<=i+10;j++)
            {
                if(s[i] - s[j] >= abs(i-j))
                {
                    k[j] = max(k[j],s[i]);
                }
            }
        }
        s = k;
        t++;
    }
    return t;
}
int n01(string s,int n)
{
    int t =0;
    int j =0;
    int fl=0;
    for(int i =0;i<n;i++)
    {
        if(i!=n-1&&s[i]=='1' && s[i+1] =='0')
        {
            j=i;
            fl =1;
            break;
        }
        if(i!=0&&s[i]=='1'&&s[i-1]=='0')
        {
            j=i;
            fl =2;
            break;
        }
    }
    if(fl==2)
        t=j;
    for(int i =j;i<n;i++)
    {
        for(int k =i+1;k<n;k++)
        {
            if(s[k]=='1')
            {
                t+=(ceil((k-i)/2));
                i =k;
            }
        }
    }

    return t;
}
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        string s;
        cin>>s;
        int n = s.length();
        int fl =0;
        for(int i =0;i<n;i++)
        {
            if(s[i]!='0' && s[i]!='1')
            {
                fl =1;
                break;
            }
        }
        if(fl==0)
            cout<<n01(s,n)<<endl;
        else if(n<=50)
            cout<<n50(s,n)<<endl;
        else
            cout<<n15(s,n)<<endl;

    }

	return 0;

}
