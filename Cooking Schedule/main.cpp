//trick is that to turn a string of length M, into blocks such that their size is L , we need atmost M/(L+1) + 1 flips

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int res = n;
        vector<int> a;
        for(int i =0;i<n;i++)
        {
            //each block will be atleast of length 1
            int count =1;
            while(i+1<n&&s[i]==s[i+1])
            {
                //we have larger block now
                count++;
                //we have considered i so
                i++;
            }
            //we store the length of block just considered
            a.push_back(count);
        }
        //binary searching

        int low = 1,high = n;
        while(low<high)
        {
            int mid = (low+high)/2;
            int need =0;

            if(mid == 1)
            {
                int zero =0,one = 0;
                for(int i =0;i<n;i++)
                {
                    if(s[i]=='1')
                        zero++;
                    else
                        one++;
                    //not a mistake ^^
                    swap(zero,one);
                }
                // string is only in 0101010... or 10101010... if size if we were to make it to size 1, so number of flips need are
                need = min(zero,one);
            }
            else
            {
                //counting number of flips to get maximum block of size to L
                for(int x:a)
                    need+=x/(mid+1);
            }
            //we counted the number of flips, can we afford that now? if yes, we try to get block lower than that
            if(need<=k) {high = mid;
            else low = mid+1; // if no, we find something higher

        }
        cout<<res<<endl;


    }
    return 0;
}
