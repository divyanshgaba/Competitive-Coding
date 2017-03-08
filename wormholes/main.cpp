/*
ID: divyans19
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int X[13],Y[13];
int n;
int partner[13];
int next[13];
bool cycle_exist()
{
       /* for(int i =1;i<=n;i++)
            fout<<i<<" - "<<partner[i]<<" ";
        fout<<endl;*/

        int pos;
        for(int i =1;i<=n;i++)
        {
            pos = i;
            //if after this loop, position is somehow 0 => there is nothing on right(no cycle) return true
            for(int j =0;j<n;j++)
            {
                pos = next[partner[pos]];
            }
            if(pos != 0)
                return true;
        }

        return false;

}
int solve()
{
    int total=0,i;

    //find first hole that has no pair
    for(i =1;i<=n;i++)
        if(partner[i]==0)
            break;

    //if all holes have pair, check if cycle exist if it does return 1 otherwise 0
    if(i>n)
    {
        if(cycle_exist())
            return 1;
        else
            return 0;
    }

    //generate all possible pairings of holes
    for(int j =i+1;j<=n;j++)
    {
        if(partner[j]==0)
        {
            partner[i] = j;
            partner[j] = i;
            total += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return total;
}


int main()
{
    ifstream fin("wormhole.in");ofstream fout("wormhole.out");

    //Input
    fin>>n;
    for(int i =1;i<=n;i++)
        fin>>X[i]>>Y[i];



    //this finds nearest hole on right of ith hole
    for(int i=1;i<=n;i++)
        for(int j =1;j<=n;j++)
            if(Y[i]==Y[j]&&X[j]>X[i])
                if(next[i]==0||
                   (X[j]-X[i] < X[next[i]] -X[i]))
                    next[i] = j;


    //output
    fout<<solve()<<endl;
    return 0;
}
