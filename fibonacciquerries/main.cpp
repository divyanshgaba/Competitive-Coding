#include <iostream>
#include <math.h>
#define mod 1000000007
using namespace std;
void multiply(int F[2][2], int M[2][2]);

/* Helper function that calculates F[][] raise to the power n and puts the
  result in F[][]
  Note that this function is desinged only for fib() and won't work as general
  power function */
void power(int F[2][2], int n);

int fib(int n)
{
  int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
      return 0;
  power(F, n-1);

  return F[0][0];
}

void multiply(int F[2][2], int M[2][2])
{
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(int F[2][2], int n)
{
  int i;
  int M[2][2] = {{1,1},{1,0}};

  // n - 1 times multiply the matrix to {{1,0},{0,1}}
  for (i = 2; i <= n; i++)
      multiply(F, M);
}
int main()
{
    int n,m,i;
    cin>>n>>m;
    int a[100008];
    for(i=0;i<n;i++)
        cin>>a[i];
    while(m--)
    {
        char c;
        cin>>c;

        if(c=='C')
           {
            int X,Y;
            cin>>X>>Y;
            a[X-1]=Y;
           }
        else if(c=='Q')
        {   int l,r;
            cin>>l>>r;
            int set_size=r-l+1,f=0,j,k,sumset=0,counter; //cout<<"set_size"<<set_size<<endl;
            int pset_size=pow(2,set_size);
            for( k=0;k<pset_size;k++)
            {    sumset=0;
               for( j=l-1, counter=0;j<r;j++,counter++)
               {
                   if(k &(1<<counter))
                    {sumset+=a[j];//cout<<a[j]<<" ";
                    sumset%=mod;
                    }

               }
            // cout<<endl;
            // cout<<"sumset"<<sumset<<"  fib(sumset)"<<fib(sumset)<<endl;
               f+=fib(sumset%mod)%mod;
               f%=mod;

            }
            cout<<f<<endl;
        }
    }

    return 0;
}
