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

int appearanceCount(int input1,int input2,string input3,string input4)
{
	int g = input1;
	int n = input2;
	string w = input3;
	string s = input4;
	int a[130],b[130];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i =0;i<g;i++)
    {
        a[w[i]]++;
        if(i<n)
            b[s[i]]++;
    }
    int ans =0;
    int flag =1;
    for(int i ='A';i<='Z';i++)
    {
        if(a[i] != b[i])
        {
            flag =0;
            break;
        }
    }
    if(flag)
    {
        for(int i ='a';i<='z';i++)
        {
            if(a[i] != b[i])
            {
                flag =0;
                break;
            }
        }
    }
    if(flag)
        ans++;
    for(int i =g;i<n;i++)
    {
        b[s[i-g]]--;
        b[s[i]]++;
        flag =1;
        for(int i ='A';i<='Z';i++)
        {
            if(a[i] != b[i])
            {
                flag =0;
                break;
            }
        }
        if(flag)
        {
            for(int i ='a';i<='z';i++)
            {
                if(a[i] != b[i])
                {
                    flag =0;
                    break;
                }
            }
        }
        if(flag)
            ans++;
    }
    return ans;
}
int main()
{
	int output;
    int ip1;
    cin >> ip1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip2;
    cin >> ip2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    string ip3;
    getline(cin, ip3);
    string ip4;
    getline(cin, ip4);
    output = appearanceCount(ip1,ip2,ip3,ip4);
    cout << output << endl;
    return 0;

	return 0;

}
