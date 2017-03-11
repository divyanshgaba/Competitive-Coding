#include<bits/stdc++.h>
using namespace std;
struct Interval
{
    int start, end;
}a[500001];

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
bool comp(Interval a,int k)
{
    return a.end<k;
}
vector<Interval> mergeIntervals(Interval arr[], int n)
{
    vector<Interval> t;
    if (n <= 0)
        return t;
    stack<Interval> s;
    sort(arr, arr+n, compareInterval);
    s.push(arr[0]);
    for (int i = 1 ; i < n; i++)
    {
        Interval top = s.top();
        if (top.end < arr[i].start)
            s.push(arr[i]);
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    while (!s.empty())
    {
        t.push_back(s.top());
        //cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return t;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,v;
        cin>>n;
        int s[n];
        for(int i =0;i<n;i++)
            cin>>s[i];
        cin>>v;
        for(int i =0;i<v;i++)
        {
            cin>>a[i].start>>a[i].end;
        }
        int count =0;
        vector<Interval> t = mergeIntervals(a,v);

        sort(t.begin(),t.end(),compareInterval);
        /*for(vector<Interval> ::iterator it = t.begin();it!=t.end();it++)
        {
            cout<<(*it).start<<" "<<(*it).end<<endl;
        }*/
        for(int i =0;i<n;i++){
            long long in = lower_bound(t.begin(),t.end(),s[i],comp) - t.begin();
            //cout<<"--"<<t[in].start<<" "<<t[in].end<<" "<<s[i]<<endl;
            if(t[in].end>=s[i]&&t[in].start<=s[i]){
                   // cout<<s[i]<<endl;
                count++;}
        }
        cout<<count<<endl;
    }
    return 0;
}
