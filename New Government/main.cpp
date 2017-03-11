#include <iostream>
#include <algorithm>
using namespace std;

bool comp(char a,char b)
{
    return a>b;
}
int cnt[27];
void print()
{
    for(int i =0;i<26;i++)
        cout<<char(i+'A')<<" ";
    cout<<endl;
    for(int i =0;i<26;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i =0;i<n;i++)
    {
        cnt[s[i]-'A']++;
    }
    for(int i =0;i<q;i++)
    {
        //print();
        int t;
        int x;
        cin>>t>>x;
        string k;
        if(t==1)
        {
            cin>>k;
            cnt[s[x-1]-'A']--;
            s[x-1]=k[0];
            cnt[s[x-1]-'A']++;
        }
        else
        {
            for(int j =0;j<26;j++)
            {

                if(cnt[j]<x)
                {
                    x=x-cnt[j];
                }
                else
                {
                    cout<<char(j+'A')<<endl;
                    break;
                }

            }
        }
    }
    return 0;
}
