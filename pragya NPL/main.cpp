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
vector<double> force,series[6];


vector<double> input(int n,string series, string angle)
{
    cout<<"Enter "<<series<<" for "<<angle<<": ";
    vector<double> t;
    for(int i = 0;i<n;i++)
    {
        double temp;
        cin>>temp;
        t.PB(temp);
    }
    cout<<"\n";
    return t;

}

void print(int n)
{
    cout<<"\n\n";
    cout<<fixed;
    cout<<"force\t0_series1\t0_series2\t120_series3\t120_series3'\t240_series4\t240_series4'\n";
    for(int i =0;i<n;i++)
    {
        cout<<setprecision(0)<<force[i]<<"\t"<<setprecision(6)<<series[0][i]<<"\t"<<series[1][i]<<"\t"<<series[2][i]<<"\t"<<series[3][i]<<"\t"<<series[4][i]<<"\t"<<series[5][i]<<"\n";
    }
    cout<<setprecision(0)<<force[n]<<"\t"<<setprecision(6)<<series[0][n]<<"\t"<<series[1][n]<<"\n\n";
}

vector<double> mid(vector<double> a, vector<double> b)
{
    assert(a.size()==b.size());
    int n = a.size();
    vector<double> t;
    for(int i = 0;i<n;i++) t.PB((a[i]+b[i])/2);
    return t;
}

vector<double> hysteresis(vector<double> a, vector<double> b)
{
    assert(a.size() == b.size());
    int n = a.size();
    vector<double> t;
    for(int i = 0;i<n;i++) t.PB(((a[i] - b[i])/a[i])*100);
    return t;
}

int main()
{
    int n;
    cout<<"Enter N: ";
    cin>>n;
    force       = input(n+1,    "force",    "");
    series[0]   = input(n+1,  "series1",  "angle0");
    series[1]   = input(n+1,  "series2",  "angle0");
    series[2]   = input(n,    "series3",  "angle120");
    series[3]   = input(n,    "series3_", "angle120");
    series[4]   = input(n,    "series4",  "angle240");
    series[5]   = input(n,    "series4_", "angle240");
    print(n);
    auto hys1   = hysteresis(series[2], series[3]);
    auto hys2   = hysteresis(series[4], series[5]);
    auto hys    = mid(hys1, hys2);


    for(auto i:hys)
        cout<<i<<" ";

	return 0;

}
