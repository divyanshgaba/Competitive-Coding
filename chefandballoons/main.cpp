#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--){
        long long int r,g,b,k,moves=1;
        cin>>r>>g>>b;
        cin>>k;
        long long int kr=0,kb=0,kg=0;
        if(k<r)
            kr=k;
        else
            kr=r;
        if(k<g)
            kg=k;
        else
            kg=g;
        if(k<b)
            kb=k;
        else
            kb=b;
       moves=moves+kb+kr+kg;
        if(kb==k)
            moves--;
        if(kr==k)
            moves--;
        if(kg==k)
            moves--;







        cout<<moves<<endl;









    }
    return 0;
}
