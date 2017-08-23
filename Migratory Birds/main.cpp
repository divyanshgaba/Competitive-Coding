#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int mem[6]={0};
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        mem[x]++;
    }
    int ans = 0, maxim = 0;
    for(int i = 0;i<6;i++)
    {
        if(maxim < mem[i])
            ans = i,maxim = mem[i];
    }
    cout<<ans<<endl;

    return 0;
}
