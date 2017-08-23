#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin>>s;
    while(s.length())
    {
        int flag = 1;
        for(int i = 0;i<s.length()-1;i++)
        {
            if(s[i] == s[i+1])
            {
                s.erase(i,2),flag = 0;
                break;
            }
        }
        if(flag) break;
    }
    if(s.length())
        cout<<s<<endl;
    else
        cout<<"Empty String\n";
    return 0;
}
