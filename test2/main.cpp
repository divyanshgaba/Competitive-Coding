#include<bits/stdc++.h>

using namespace std;

int main()
{
    ofstream fout ("input.txt");
    int n = 50;
    for(int i = 0;i<n;i++)
    {
        fout<<rand()%100<<" "<<rand()%100<<" "<<rand()%100<<" "<<rand()%1000<<" "<<rand()%1000<<" "<<rand()%1000<<endl;
    }
    return 0;
}
