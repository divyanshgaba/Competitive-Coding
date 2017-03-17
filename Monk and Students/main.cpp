#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
vector<pair<int,int> >points;

pair<int,int> fraction(int m,int n)
{
    int c = min(m,n);
    pair<int,int> qr=(make_pair(m,n));
    for(int i =2;i<=sqrt(c);i++)
    {
        while(qr.first%i==0 && qr.second%i==0)
        {
            qr.first/=i;
            qr.second/=i;
        }
    }
    return qr;
}
bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.first <b.first;
}
bool cmp(const vector<pair<int,int> > &a1, const pair<int,int> &a2){
    for(int i = 0; i< a1.size();i++){
        if (a1[i] < a2)
            return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        pair<int,int> x,y;
        cin>>x.first>>y.first;
        cin>>x.second>>y.second;
        int m = x.second-x.first;
        int n = y.second-y.first;
        pair<int,int> qr = fraction(m,n);
        int count =0;
        for(int j =0;j<=m;j+=qr.first)
            count++;
        points.push_back(make_pair(count,i));
       // points[i].second = i;

    }
    sort(points.begin(),points.end(),comp);
    int q;
    cin>>q;
    for(int i =0;i<q;i++)
    {
        int x;
        cin>>x;
        int low = lower_bound(points.begin(),points.end(),x,cmp) - points.begin();
        int high = upper_bound(points.begin(),points.end(),x,cmp) - points.begin();
        int y = abs(points[low].first - x);
        int z = abs(points[high].first -x);
        if(y==z)
            cout<<min(points[low].second,points[high].second)<<endl;
        else if (y>z)
            cout<<points[high].second<<endl;
        else
            cout<<points[low].second<<endl;

    }
    return 0;
}
