#include<iostream>
#include<math.h>

int main()
{
    int r,p=0,x=0;
    float s,area_t,area_c;
    int arr[100];
    std::cin>>r;
    for(int a=r;a<r+220;a++)
    {
        for(int b=a;b<a+220;b++)
        {
            for(int c=b;c<b+220;c++)
            {
                s=(a+b+c)/2.0;
                area_t=sqrt(s*(s-a)*(s-b)*(s-c));
                area_c=3.14*r*r;
                if(area_t>area_c)
                {
                    if(r==area_t/s&&a<b&&a<c&&b<c)
                    {
                        p++;
                        arr[x]=a;
                        arr[x+1]=b;
                        arr[x+2]=c;
                        x+=3;
                    }
                }
            }
        }
    }
    arr[x]='\0';
    std::cout<<p<<std::endl;
    for(int i=0;arr[i]!='\0';)
    {
        for (int j=0;j<3;j++)
        {
            std::cout<<arr[i]<<" ";
            i++;
        }
        std::cout<<std::endl;
    }
}
