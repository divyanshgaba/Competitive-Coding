#include <iostream>

using namespace std;
int n;
int d,r;
int s[101];
int answer(int i)
{
    if(i==n)
        return 0;
    int sum=0;
    int temp =0;
    for(int j =i;j<i+r;j++)
        sum+=s[j];
    if(sum==d)
        temp =1;
    return temp + answer(i+1);

}
int main()
{

    cin>>n;

    for(int i =0;i<n;i++)
        cin>>s[i];

    cin>>d>>r;
    cout<<answer(0);
    return 0;
}
