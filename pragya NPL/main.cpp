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

inline double round(double val)
{
    val = val*10000.0;
    if( val < 0 ) val =  ceil(val - 0.5);
    else val =  floor(val + 0.5);
    val = val/10000.0;
    return val;
}
inline double avg(double a,double b)
{
    return (a+b)/2.0;
}
inline double avg(double a, double b, double c)
{
    return (a+b+c)/3.0;
}

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

void print_input(int n)
{
    cout<<"\n\n";
    cout<<fixed;
    cout<<"Force\t0_series1\t0_series2\t120_series3\t120_series3'\t240_series4\t240_series4'\n";
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
    for(int i = 0;i<n;i++) t.PB(abs(((a[i] - b[i])/a[i])*100));
    return t;
}

void print_hystersis(int n)
{
    auto hys1   = hysteresis(series[2], series[3]);
    auto hys2   = hysteresis(series[4], series[5]);
    auto hys    = mid(hys1, hys2);
    cout<<"\n\n";
    cout<<"Force\tHystersis_3-3'\tHystersis_4-4'\tAvg Hystersis\n";
    for(int i = 1;i<n;i++)
    {
        cout<<setprecision(0)<<force[i]<<setprecision(4)<<"\t\t"<<round(hys1[i])<<"\t\t"<<round(hys2[i])<<"\t\t"<<round(hys[i])<<endl;
    }
    cout<<"\n\n";
}

vector<double> repeatability(vector<double> a, vector<double> b)
{
    assert(a.size() == b.size());
    int n = a.size();
    vector<double> reap;
    for(int i = 0;i<n;i++)
    {
        auto temp = max(a[i],b[i]) - min(a[i],b[i]);
        temp = temp/(avg(a[i],b[i]));
        temp *=100;
        reap.PB(temp);
    }
    return reap;
}

void print_repeatability(int n)
{
    auto reap = repeatability(series[0],series[1]);
    cout<<"\n\n";
    cout<<"Force\tRepeatability\n";
    for(int i = 1;i<n;i++)
    {
        cout<<setprecision(0)<<force[i]<<setprecision(4)<<"\t"<<round(reap[i])<<"%"<<endl;
    }
    cout<<"\n\n";
}

vector<double> reproducability(vector<double> a, vector<double> b, vector<double> c)
{
    assert(a.size()-1 == b.size() && b.size() == c.size());
    int n = a.size()-1;
    vector<double> rep;
    for(int i = 0;i<n;i++)
    {
        auto temp = max(max(a[i],b[i]),c[i]) - min(min(a[i],b[i]), c[i]);
        temp = abs(temp/avg(a[i],b[i],c[i]));
        temp *=100;
        rep.PB(temp);
    }
    return rep;
}
void print_reproducability(int n)
{
    auto rep = reproducability(series[0],series[2],series[4]);
    cout<<"\n\n";
    cout<<"Force\tReproducability\n";
    for(int i = 1;i<n;i++)
    {
        cout<<setprecision(0)<<force[i]<<setprecision(4)<<"\t"<<round(rep[i])<<"%"<<endl;
    }
    cout<<"\n\n";
}

void print_results(int n)
{
    //TODO
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
    print_input(n);
    print_hystersis(n);
    print_repeatability(n);
    print_reproducability(n);

	return 0;

}

/*
11
0 2 4 6 8 10 12 14 16 18 20 0
0.00000 0.13204 0.26408 0.39613 0.52820 0.66030 0.79241 0.92454 1.05673 1.18893 1.32112 0.00050
0.00000 0.13197 0.26394 0.39594 0.52795 0.66002 0.79210 0.92418 1.05630 1.18850 1.32073 0.00080
0.00000 0.13209 0.26418 0.39625 0.52837 0.66049 0.79265 0.92487 1.05710 1.18939 1.32168
0.00030 0.13205 0.26417 0.39627 0.52839 0.66055 0.79271 0.92490 1.05714 1.18944 1.32168
0.00000 0.13201 0.26402 0.39608 0.52814 0.66020 0.79230 0.92445 1.05660 1.18883 1.32103
0.00110 0.13198 0.26402 0.39606 0.52815 0.66020 0.79228 0.92445 1.05653 1.18881 1.32103

*/
