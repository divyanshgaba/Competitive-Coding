#include<bits/stdc++.h>

using namespace std;

int main()
{
    ofstream fout ("input.csv");
    int n = 10;
    for(int i = 0;i<n;i++)
    {
        fout<<rand()%5<<endl;
    }

    return 0;
}
