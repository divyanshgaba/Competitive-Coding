#include <iostream>

using namespace std;
int m[10001];
int q,x;
int coins=-1;
int a[10001];
int n;
int size=0;
int val =0;
int ith=0;
int k =0;
void push()
{
    m[k++]=a[ith];
    val+=a[ith++];
    size++;
    if(val == x)
        coins = size;
}
void pop()
{
    val -=m[--k];
    size--;
    if(val == x)
        coins = size;
}
int main()
{
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>q>>x;
    for(int i =0;i<q;i++)
    {
        string s;
        cin>>s;
        if(coins!=-1)
            continue;
        if(s[0]=='H')
        {
            push();
        }
        else
        {
            pop();
        }
    }
    cout<<coins<<endl;
    return 0;
}
