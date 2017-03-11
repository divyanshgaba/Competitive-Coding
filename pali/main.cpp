#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s,hold,temp;
    cin>>s;
    int len = s.length();
    hold = s.substr(0,len/2);
    if(len%2==0)
        temp = s.substr(len/2,len);
    else
        temp = s.substr(len/2+1,len);
    reverse(temp.begin(),temp.end());
    //cout<<hold<<" "<<temp;
    if(hold == temp)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
