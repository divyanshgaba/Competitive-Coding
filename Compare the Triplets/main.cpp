#include <iostream>

using namespace std;

int main()
{
    int ascore=0,bscore=0;
    int a[3];
    int b[3];
    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];
    for(int i =0;i<3;i++)
    {
        if(a[i]==b[i])
            continue;
        else if(a[i]>b[i])
            ascore++;
        else
            bscore++;
    }
    cout<<ascore<<" "<<bscore<<endl;

    return 0;
}
