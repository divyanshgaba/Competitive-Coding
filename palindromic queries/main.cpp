#include <iostream>
#include <vector>
#include <stdbool.h>
#include <algorithm>
using namespace std;
string str;
bool ispal(int k, int l,int i , int j)
{


    int z=0;
    char temp[1000009];
    int flag1=1,flag2=1;
    for(int x = k;x<=l;)
    {
        if(flag2==1&&x>=i && x<=j)
        {
                        int hold =x;
            if(l<=j)
            {
                x=l;
            }
            else
                x=j;

            while(x>=hold)
            {
                temp[z++] = str[x--];
            }

            if(l<j)
                flag1=0;
            flag2=0;
            x=j+1;

        }
        else{
            temp[z++] =str[x++];
        }
        if(flag1==0)
            break;

    }
    int y =0;
    cout<<temp;
    z--;
    while(y<z)
    {
        if(temp[y++] != temp[z--])
            return false;
    }
    return true;
}
/*void print_elem(char c)
{
    cout<<c;
}*/
int main()
{

    cin>>str;
    int n;
    cin>>n;
    while(n--)
    {
        int i,j,k,l;
        cin>>i>>j>>k>>l;
        //for_each(dup.begin(),dup.end(),print_elem);
        //cout<<endl;
        if(ispal(k-1,l-1,i-1,j-1))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
