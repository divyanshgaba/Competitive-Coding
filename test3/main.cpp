#include<bits/stdc++.h>
using namespace std;
const long long maxval = 1e9;
int main()
{
    ofstream fout("input03.in");
    int t = rand()%1000 + 99000;
    fout<<t<<endl;
    while(t--)
    {
        long long a = maxval - rand()%1000 ;
        long long b = maxval - rand()%1000 ;
        fout<<a<<" "<<b<<endl;
    }
	return 0;
}
