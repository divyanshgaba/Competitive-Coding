#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    while(true)
    {
        int temp;
        cin>>temp;
                if(temp==42)
            break;
        v.push_back(temp);


    }
    int size = v.size();
    for(int i =0;i<size;i++)
        cout<<v[i]<<endl;
    return 0;
}
