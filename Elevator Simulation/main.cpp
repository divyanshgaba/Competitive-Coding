#include <iostream>

using namespace std;
struct person
{
    int id,t,fl;
};
bool comp(person a,person b)
{
    return a.t<b.t;
}
int main()
{
    int n,w,c,m;
    cin>>n>>w>>c>>m;
    person p[n];
    for(int i =0;i<n;i++)
        cin>>p[i].id>>p[i].t>>p[i].fl;
    sort(p,p+n,comp);
    priority_queue<person> elevator;
    priority_queue<person> waiting;

    return 0;
}
