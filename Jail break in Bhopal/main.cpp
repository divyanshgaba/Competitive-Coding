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
int GetJumpCount(int input1,int input2,vector < int > input3)
{

	int x = input1,y = input2;
	int ans =0;
	for(auto i:input3)
    {
        if(i>0 && i<= x)
            ans++;
        else if(i >x)
        {
            int mid = i/(x-y);
            if(i%(x-y) > y)
                mid+=1;
            ans+=mid;
        }
    }
    return ans;
}

int main() {
    int output;
    int ip1;
    cin >> ip1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip2;
    cin >> ip2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip3_size = 0;
    cin >> ip3_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> ip3;
    int ip3_item;
    for(int ip3_i=0; ip3_i<ip3_size; ip3_i++) {
        cin >> ip3_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        ip3.push_back(ip3_item);
    }
    output = GetJumpCount(ip1,ip2,ip3);
    cout << output << endl;
    return 0;
}

