#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[20001];
int usize[20001];
void init()
{
    for(int i = 0;i<20001;i++)
    {
        arr[ i ] = i ;
        usize[ i ] = 1;
    }
}
int root(int a)
{
    while(arr[a]!=a)
    {
        a=arr[a];
    }
    return a;
}
void union_(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(usize[root_A] < usize[root_B ])
    {
        arr[ root_A ] = arr[root_B];
        usize[root_B] += usize[root_A];
    }
    else
    {
        arr[ root_B ] = arr[root_A];
        usize[root_A] += usize[root_B];
    }

}
void print_elem(int a)
{
    cout<<a<<" ";
}
int main()
{
    int test;
    cin>>test;
    for(int z = 1;z<=test;z++)
    {
        int n;
        cin>>n;
        int a[n+1],b[n+1];
        init();
        vector<int> vec;
        for(int i =1;i<=n;i++)
        {
            cin>>a[i]>>b[i];
            union_(a[i],b[i]);
            vec.push_back(a[i]);
            vec.push_back(b[i]);

        }
        for_each(vec.begin(),vec.end(),print_elem);
        cout<<endl;
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        for_each(vec.begin(),vec.end(),print_elem);
        int size = vec.size();
        cout<<endl;
        vector<int> hold;
        int max=0;
        for(int i =0;i<size;i++)
        {
            hold.push_back(arr[vec[i]]);
            if(max<usize[vec[i]])
                max = usize[vec[i]];
        }
        sort(hold.begin(),hold.end());
        hold.erase(unique(hold.begin(),hold.end()),hold.end());
        int count = hold.size();
        for_each(hold.begin(),hold.end(),print_elem);
        cout<<endl;
        cout<<"Case "<<z<<": "<<count<<" "<<max<<endl;
    }
    return 0;
}
