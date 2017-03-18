#include <iostream>

using namespace std;
pair<int,int> ans[250];

int main()
{
    int mul=5;
    for(int i =3;i<=200;)
    {
        ans[i] = make_pair(i+7,3);
        ans[i+7] = make_pair(i,3);
        i=3*mul;
        mul+=4;
    }
    mul=3;
    for(int i =6;i<=200;)
    {
        ans[i] = make_pair(i+1,1);
        ans[i+1] = make_pair(i,1);
        i=6*mul;
        mul+=2;
    }
    mul=4;
    for(int i =4;i<=200;)
    {
        ans[i] = make_pair(i+5,3);
        ans[i+5] = make_pair(i,3);
        i=4*mul;
        mul+=3;
    }
    mul=7;
    for(int i =2;i<=200;)
    {
        ans[i] = make_pair(i+9,2);
        ans[i+9] = make_pair(i,2);
        i=2*mul;
        mul+=6;
    }
    mul=3;
    for(int i =5;i<=200;)
    {
        ans[i] = make_pair(i+3,2);
        ans[i+3] = make_pair(i,2);
        i=5*mul + mul-1;
        mul+=2;
    }
    for(int i =1;i<=200;)
    {
        ans[i] = make_pair(i+11,1);
        ans[i+11] = make_pair(i,1);
        i+=12;
    }
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        cout<<ans[n].first<<" ";
        switch(ans[n].second)
        {
        case 1:
            cout<<"WS"<<endl;
            break;
        case 2:
            cout<<"MS"<<endl;
            break;
        case 3:
            cout<<"AS"<<endl;
            break;
        }
    }

    return 0;
}
