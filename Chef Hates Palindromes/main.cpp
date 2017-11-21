#include<iostream>
#include<algorithm>
using namespace std;

bool pally(string s)
{
    int n = s.length();
    for(int i = 0;i<n;i++)
    {
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
int answer(string s)
{
    int n = s.length();
    if(n>=10)
        return 4;
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = i;j<n;j++)
        {
            if(pally(s.substr(i,j-i+1)))
                ans = max(ans,j-i+1);
        }
    }
    return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int z = 0;z<t;z++)
    {
		int n,k;
		cin>>n>>k;
		if(k==1)
        {
            cout<<n<<" ";
            for(int i = 0;i<n;i++)
                cout<<'a';
            cout<<endl;
            continue;
        }
        else if(k>=3)
        {
            cout<<1<<" ";
            string s = "abc";
            for(int i = 0;i<n;i++)
                cout<<s[i%3];
            cout<<endl;

        }
        else if(n==2)
        {
            cout<<"1 ab"<<endl;
        }
        else if(n==8)
        {
            cout<<"3 aaababbb"<<endl;
        }
        else
        {
            string s = "bbabaa";
            string y= "";
            int last = 0;
            for(int i  = 0;i<n-n%3;i++)
            {
                y+=s[last = i%6];
            }
            if((n/3)>=3 && (n/3)&1)
                reverse(y.begin(),y.end());
            for(int i = 0;i<n%3;i++)
                y+="a";
            if(!((n/3)>=3 && (n/3)&1))
                reverse(y.begin(),y.end());
            cout<<answer(y)<<" "<<y<<endl;
        }
    }
	return 0;

}
