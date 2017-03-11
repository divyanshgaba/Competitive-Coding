#include <iostream>

using namespace std;
int main()
{
    string s[3];
    s[0]= "..O..";
    s[1]="O.o.O";
    s[2]="..O..";
    int r,c;
    cin>>r>>c;
    for(int i =0;i<r;i++)
    {
        for(int j =0;j<3;j++)
        {
            for(int k =0;k<c;k++)
                cout<<s[j];
            cout<<endl;
        }
    }
    return 0;
}
