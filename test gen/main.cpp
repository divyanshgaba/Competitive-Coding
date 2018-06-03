
#include<bits/stdc++.h>
using namespace std;
const int X = 1e9;
int main()
{

    cout<<100<<endl;
    srand(time(NULL));
    for(int i = 0;i<100;i++)
    {
        cout<<10<<endl;
        for(int j = 0;j<10;j++)
            cout<<rand()%X + 1<<" ";
        cout<<endl;
    }
	return 0;

}
