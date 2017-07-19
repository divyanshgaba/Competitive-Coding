#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.out");
    int t;
    fin>>t;
    while(t--)
    {
        int n,m;
        fin>>n>>m;
        int job[m];
        int done[n];
        memset(done,0,sizeof(done));
        for(int i = 0;i<m ;i++)
            fin>>job[i], done[job[i]-1]=1;
        bool flag = true;
        vector<int> chef, ass;
        for(int i = 0 ;i<n;i++)
        {
            if(done[i] == 1)
                continue;
            if(flag)
                chef.push_back(i+1);
            else
                ass.push_back(i+1);
            flag = !flag;
        }
        for(auto i:chef)
        {
            fout<<i<<" ";
        }
        fout<<endl;
        for(auto i: ass)
        {
            fout<<i<<" ";
        }
        fout<<endl;


    }
    return 0;
}
