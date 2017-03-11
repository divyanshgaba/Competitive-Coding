#include <iostream>
#include<cmath>
using namespace std;
bool checkprime(int N) {
        if(N==0||N==1)
            return false;
        if(N==2)
            return true;
        for(int i =3;i<sqrt(N);i+=2)
            if(N%i==0)
                return false;

        return true;
    }
int main()
{
    int n;
    cin>>n;
    int i =n;
    int c=0,d=0;
    for(int i =n;;i++)
    {
        if(checkprime(i))
            break;
        c++;
    }
    for(int i =n-1;;i--)
    {
        if(checkprime(i))
            break;
        d++;
    }
    if(i<=0)
        d=10000000;
    cout<<min(c,d)<<endl;
    return 0;
}
