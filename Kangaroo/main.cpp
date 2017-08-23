#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double x1,v1,x2,v2;
    cin>>x1>>v1>>x2>>v2;
    if ((x2-x1)/(v1-v2) == int((x2-x1)/(v1-v2)) && (x2-x1)/(v1-v2) >=0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
