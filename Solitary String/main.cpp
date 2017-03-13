#include <iostream>
#include <cstring>
using namespace std;
int mem[30];
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        int max =0;
        int n = s.length();
        memset(mem,0,sizeof(mem));
        for(int i =0;i<n;i++)
            mem[s[i]-'a']++;
        int bw;
        int mf =0;
        for(int i =0;i<27;i++)
        {
            if(mem[i]>=2)
            {
                mf=1;
                bw=0;
                int flag =0;
                for(int j =0;j<n&&mem[i]>=1;j++)
                {
                    if(flag==1)
                        bw++;
                    if(s[j]==char(i+'a'))
                    {
                        mem[i]--;
                        flag =1;
                    }
                }
                if(bw>max)
                    max=bw;
            }

        }
        if(mf==0)
            cout<<-1<<endl;
        else
            cout<<max-1<<endl;
    }
    return 0;
}
