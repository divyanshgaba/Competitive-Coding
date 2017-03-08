#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int result[t];
    for(int a=0;a<t;a++)
    {
        int n;
        cin>>n;
        int arr_x[n],arr_y[n];
        for(int b=0;b<n;b++)
        {

                cin>>arr_x[b];

        }
        for(int b=0;b<n;b++)
        {

                cin>>arr_y[b];
        }

        int sum=0,sum1=0;
        for(int b=0;b<n;b++)
        {
            switch(b%2)
            {
                case 1:
                    sum+=arr_x[b];
                    sum1+=arr_y[b];
                    break;
                case 0:
                    sum+=arr_y[b];
                    sum1+=arr_x[b];
                    break;
            }
        }


        if(sum>sum1)
            result[a]=sum1;
        else
            result[a]=sum;
    }
    for(int a=0;a<t;a++)
    {
        cout<<result[a]<<endl;
    }


    return 0;
}
