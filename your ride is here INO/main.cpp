#include <iostream>
#include <fstream>
#define NUM(A) (A - 'A' + 1)
#include <string>
using namespace std;

int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    char s1[8],s2[8];
    fin>>s1;
    fin>>s2;
    int p1=1,p2=1;
    for(int i;s1[i]!='\0';i++ )
        p1=(p1*NUM(s1[i]))%47;
    for(int i;s2[i]!='\0';i++ )
        p1=(p2*NUM(s2[i]))%47;
    if(p1==p2)
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
    return 0;
}
