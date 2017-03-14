#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int cnt =1;
    for(int i =1;s[i]!='\0';i++)
        if(isupper(s[i]))
            cnt++;
    cout<<cnt<<endl;
    return 0;
}
