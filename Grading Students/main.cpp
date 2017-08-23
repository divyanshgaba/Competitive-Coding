#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test;
    cin>>test;
    while(test--)
    {
        int marks;
        cin>>marks;
        if(marks>=38)
            cout<<(marks/5)*5 + ((round(double(marks%5)/5)==1)?5:marks%5)<<endl;
        else
            cout<<marks<<endl;
    }
    return 0;
}
