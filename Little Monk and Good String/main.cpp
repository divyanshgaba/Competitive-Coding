#include <iostream>

using namespace std;
int len[100001];
int main()
{
    string s;
    cin>>s;
    int max =0;
    int lens = s.length();
    for(int i =0;i<lens;i++)
    {
        if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u')
        {
            len[i+1] = len[i] +1;
            if(max<len[i+1])
                max=len[i+1];
        }
    }

    cout<<max<<endl;
    return 0;
}
