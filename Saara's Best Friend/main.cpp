#include <iostream>
#include <set>
using namespace std;
set<char> st;
int main()
{
    string s;
    cin>>s;
    long long k=0;
    int n = s.length();
    for(int i =0;i<n;i++)
    {
        if(s[i]=='e'||s[i]=='a'||s[i]=='o'||s[i]=='u'||s[i]=='i'||s[i]=='A'||s[i]=='I'||s[i]=='E'||s[i]=='O'||s[i]=='U')
            k++;
        st.insert(s[i]);
    }
    cout<<k*k<<" "<<st.size()<<endl;

    return 0;
}
