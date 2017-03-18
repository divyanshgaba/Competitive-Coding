#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    long long i,j;
    while(scanf("%d %d\n",&i,&j) != EOF)
    {

        long long ic=1,jc=1;
        cin>>i>>j;
        long long temp =i;
        while(temp!=1)
        {
            if(temp%2 != 0)
            {
                temp = 3*temp +1;
                temp = temp/2;
                            ic+=2;            }
            else{
                temp=temp/2;
                ic++;
            }

        }
        temp = j;
        while(temp!=1)
        {
            if(temp%2 != 0)
            {
                temp = 3*temp +1;
                temp = temp/2;
                jc+=2;
            }
            else
            {
                temp=temp/2;
                jc++;
            }

        }
        cout<<i<<" "<<j<<" "<<max(jc,ic)<<endl;
    }
    return 0;
}
