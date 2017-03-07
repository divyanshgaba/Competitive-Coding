#include <iostream>

using namespace std;
void swap(double *x,double *y)
{
    double temp =*x;
    *x=*y;
    *y=temp;
}

int main()
{
    double x,y;
    cin>>x>>y;
    swap(&x,&y);
    cout<<x<<y;
    return 0;
}
