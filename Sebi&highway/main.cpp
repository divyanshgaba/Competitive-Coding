#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int ss,sg,fg,m,t;
        cin>>ss>>sg>>fg>>m>>t;
        float distance = (m) *50;
        float speed = (distance*3600)/t;
        speed /=1000;
        speed +=ss;
        if(fabs(speed-sg) < fabs(speed-fg))
            cout<<"SEBI"<<endl;
        else if(fabs(speed-sg)>fabs(speed-fg))
            cout<<"FATHER"<<endl;
        else
            cout<<"DRAW"<<endl;
    }
    return 0;
}
