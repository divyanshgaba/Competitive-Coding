#include<iostream>
#include<vector>
using namespace std;
const int N = 1e6+1;
vector<int> left_ans;
int right_ans[N+1];
bool comp[N+1];
void prime();
int main()
{
	prime();
	int q;
	cin>>q;
    for(int _ = 0;_<q;_++)
    {
        int a,b;
        cin>>a>>b;
        int ind = lower_bound(left_ans.begin(),left_ans.end(),a) - left_ans.begin();
        cout<<max(0,right_ans[b]-left_ans[ind])<<endl;
    }
	return 0;

}
void prime()
{

    for(int i = 2;i*i<=N;i++)
    {
        if(!comp[i])
        {
            for(int j = i+i;j<=N;j+=i)
                comp[j]=true;
        }
    }
    for(int i = 2;i<=N;i++)
    {
        if(!comp[i])
            left_ans.push_back(i);
    }
    int j = left_ans.size()-1;
    for(int i = N;i>=2;i--)
    {
        if(i < left_ans[j])
            j--;
        right_ans[i] = left_ans[j];
    }
}
