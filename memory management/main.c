#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

    int test;
    scanf("%d",&test);
    while(test--)
    {
        int p,s,n;
        scanf("%d %d %d",&p,&s,&n);
        long long memo[n];
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&memo[i]);
        }
        int fifo[p],lru[p];
        for(i=0;i<p&&i<n;i++)
        {
            int page = floor(memo[i]/s);
            fifo[i]=page;
            lru[i]=page;
        }
        int kf=0,kl=0;
        int page;
        int cf=0,cl=0;
        int j,ff=0,lf=0;
        for(i=p;i<n;i++)
        {
            ff=0;
            lf=0;
            page=floor(memo[i]/s);

            for(j=0;j<p;j++)
            {
                if(fifo[j]==page)
                {

                    ff=1;
                }
                if(lru[j]==page)
                {
                    int temp=lru[j];
                    int hsh=j;
                    if(kl!=0){
                    while(hsh!=(kl-1))
                    {
                        lru[hsh]=lru[(hsh+1)%p];
                        hsh=(hsh+1)%p;
                    }}
                    else
                    {
                        int hsh;
                        for(hsh=1;hsh<p;hsh++)
                        {
                            lru[hsh]=lru[(hsh+1)%p];
                        }

                    }


                    kl++;
                    lru[kl-1]=temp;
                    lf=1;
                }
            }
            if(ff!=1)
            {
                kf=kf%p;
                fifo[kf++]=page;
                cf++;
            }
            if(lf!=1)
            {
                kl=kl%p;
                lru[kl++]=page;
                cl++;
            }
        }
        if(cf>cl)
        {
            printf("yes ");
        }
        else
            printf("no ");
        printf("%d %d\n",cf,cl);

    }

    return 0;
}
