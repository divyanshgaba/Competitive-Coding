#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dep[1001];
int size[1001];
    int n,d;

int root(int i)
{
    while(dep[i] != i)
    {
        i =dep[i];
    }
    return i;
}
void union_(int a,int b)
{
    int ar =dep[a];
    for(int i =1;i<=n;i++)
    {
        if(dep[i] == ar)
            dep[i]=dep[b];
    }

}
int main()
{
    cin>>n>>d;
    for(int i =0;i<=n;i++)
    {
        dep[i]=i;
        size[i]=1;
    }
    for(int i =0;i<d;i++)
    {
        int a,b;
        cin>>a>>b;
        union_(b,a);
    }
    vector<int> hold;
    for(int i =1;i<=n;i++)
    {
        hold.push_back(dep[i]);

    }
    sort(hold.begin(),hold.end());
    hold.erase(unique(hold.begin(),hold.end()),hold.end());
    int min=n;
    int temp = hold.size();
    for(int i =0;i<temp;i++)
    {
        int count=0;
        for(int j =1;j<=n;j++)
        {
            if(dep[j]==hold[i])
                count++;
        }
        if(count<min)
            min = count;
    }
    cout<<min<<endl;
    return 0;
}
