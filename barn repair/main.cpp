/*
ID: divyans19
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdbool.h>
#include <fstream>
using namespace std;
ifstream fin("barn1.in");ofstream fout("barn1.out");
bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}

int main()
{
    int m,s,c;
    fin>>m>>s>>c;
    vector <int> a(c,0);
    vector <pair<int,int> > arr(c-1,pair<int,int>(make_pair(0,0)));
    for(int i =0;i<c;i++)
    {

        fin>>a[i];
    }
    if(m>=c)
    {
        fout<<c<<endl;
        return 0;
    }
    sort(a.begin(),a.end());
    for(int i =0;i<c-1;i++)
    {
        arr[i].first =a[i+1]-a[i];
        arr[i].second = i;
    }
    sort(arr.rbegin(),arr.rend());
    sort(arr.begin(),arr.begin()+m-1,comp);
    int sum =0;
    int temp =0;

    for(int i =0;i<m-1;i++)
    {
      //  fout<<arr[i].first<<" "<<arr[i].second<<endl;
        sum += a[arr[i].second] -a[temp] +1;
       // fout<<"::"<<a[arr[i].second] -a[temp]<<endl;
        temp = arr[i].second+1;
    }
    sum +=a[c-1] - a[temp]+1;
   // fout<<temp<<endl;
    fout<<sum<<endl;
    return 0;
}
