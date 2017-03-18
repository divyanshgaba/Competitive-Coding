#include <iostream>

using namespace std;

int main()
{
    long long n,ev,od,sumev,sumod,numev,numod;
    cin>>n;
    if(n%2!=0)
    {
        od=n;
        ev=n-1;
    }
    else
    {
        ev=n;
        od=n-1;
    }
    numod = (1+od)/2;
    numev = (2+ev)/2 -1;
    sumod = (numod*(1+od))/2;
    sumev = (numev*(2+ev))/2;
    cout<<sumod<<" "<<sumev<<endl;

    return 0;
}
