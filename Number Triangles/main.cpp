/*
ID: divyans19
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
vector<vector<int> > tr;
int n;
int ans[1001][1001];
int answer(int i,int j)
{
    if(i==n)
        return 0;
    if(ans[i][j]!=-1)
        return ans[i][j];
    int temp = tr[i][j] +max(answer(i+1,j),answer(i+1,j+1));
    ans[i][j] =temp;
    return temp;
}
int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    fin>>n;
    for(int i =0;i<n;i++)
    {
        vector<int> lev;
        for(int j =0;j<=i;j++)
        {
            int node;
            fin>>node;
            lev.push_back(node);
            ans[i][j]=-1;
        }
        tr.push_back(lev);
    }
    fout<<answer(0,0)<<endl;
    return 0;
}
