#include <iostream>
#include <array>
#define MOD 1000000007
using namespace std;
int n;
char c[100001];
array<int,6> a;
bool check(string s)
{
    array<int,6> a = ::a;
    for(int i =0;i<n-1;i++)
    {
        if(s[i]=='r')
        {
            if(s[i+1]=='b')
            {
                if(a[0]==0)
                    return false;
                a[0]-=1;
            }
            else if(s[i+1]=='g')
            {
                if(a[1]==0)
                    return false;
                a[1]-=1;
            }

        }
        else if(s[i]=='b')
        {
            if(s[i+1]=='r')
            {
                if(a[2]==0)
                    return false;
                a[2]-=1;
            }
            else if(s[i+1]=='g')
            {
                if(a[3]==0)
                    return false;
                a[3]-=1;
            }
        }
        else
        {
            if(s[i+1]=='r')
            {
                if(a[4]==0)
                    return false;
                a[4]-=1;
            }
            else if(s[i+1]=='b')
            {
                if(a[5]==0)
                    return false;
                a[5]-=1;
            }
        }
    }
    return true;
}
void print(array<int,6> a)
{
    for(int i =0;i<6;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int answer(int i)
{
    if(i==n-1)
    {
        //cout<<" winner: "<<c<<endl;
        return 1;
    }
    //cout<<c<<endl;    print(a);    cout<<endl;
    int temp=0;
    switch(c[i])
    {
        case 'r':
            if(a[0]>0)
            {
                c[i+1]='b';
                a[0]--;
                temp=(temp+answer(i+1))%MOD;
                a[0]++;
            }
            if(a[1]>0)
            {
                c[i+1]='g';
                a[1]--;
                temp=(temp+answer(i+1))%MOD;
                a[1]++;
            }
            c[i+1]='r';
            temp=(temp+answer(i+1))%MOD;

            break;
        case 'b':
            if(a[2]>0)
            {
                c[i+1]='r';
                a[2]--;
                temp=(temp+answer(i+1))%MOD;
                a[2]++;
            }
            if(a[3]>0)
            {
                c[i+1]='g';
                a[3]--;
                temp=(temp+answer(i+1))%MOD;
                a[3]++;
            }
            c[i+1]='b';
            temp=(temp+answer(i+1))%MOD;

            break;
        case 'g':
            if(a[4]>0)
            {
                c[i+1]='r';
                a[4]--;
                temp=(temp+answer(i+1))%MOD;
                a[4]++;
            }
            if(a[5]>0)
            {
                c[i+1]='b';
                a[5]--;
                temp=(temp+answer(i+1))%MOD;
                a[5]++;
            }
            c[i+1]='g';

            temp=(temp+answer(i+1))%MOD;

            break;
    }
    return temp;

}
int main()
{

    cin>>n;
    for(int i =0;i<6;i++)
    {
        cin>>a[i];
    }
    int i;
    int sum=0;
    c[0]='r';
    sum+=answer(0);
    c[0]='b';
    sum+=answer(0);
    c[0]='g';
    sum+=answer(0);
    cout<<sum<<endl;
    return 0;
}
