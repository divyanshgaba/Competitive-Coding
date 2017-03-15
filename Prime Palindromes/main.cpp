#include <iostream>
#include <cmath>
using namespace std;
int a,b;

int prime(int number)
{
    if(number == 2)
        return 1;
    if(number%2==0||number==1)
        return 0;
    for(int i =3;i<=sqrt(number);i+=2)
        if(number%i==0)
            return 0;
    cout<<number<<endl;
    return 1;

}

int palindrome(int st,int en,int digit)
{

    if(st>en)
        return 0;
    if (st==en)
        {
            return digit*pow(10,st);
        }

    return digit*((pow(10,en-st))+pow(10,st)) + palindrome(st+1,en-1,digit+1);


}
int main()
{
    //cout<<prime(11)<<endl;
    cin>>a>>b;
    int lena=0,lenb=0;
    int temp =a;
    while(temp!=0)
    {
        lena++;
        temp /=10;
    }
    temp =b;
    while(temp!=0)
    {
        lenb++;
        temp/=10;
    }
    //cout<<lena<<" "<<lenb<<endl;
    cout<<palindrome(0,2,1)<<endl;
    return 0;
}
