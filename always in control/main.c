#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double val(int n)
{
    switch(n)
    {
    case 2:return 1.880;
            break;
    case 3:
            return 1.023;
        break;
    case 4:
            return 0.729;
        break;
    case 5:
            return 0.577;
        break;
    case 6:
            return 0.483;
        break;
    case 7:
            return 0.419;
        break;
    case 8:
            return 0.373;
        break;
    case 9:
            return 0.337;
        break;
    }
    return 0.308;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d",&x);
        int n;
        scanf("%d",&n);
        int i,j;
        int data[x];
        for(i=0;i<x;i++)
        {
            scanf("%d",&data[i]);
        }
        double A2=val(n);
        int count=(x/n);
        int extr=x%n;
        double avg=0,range=0,gavg=0,grange=0;
        for(i=0;i<x;i=i+n)
        {
            avg=0;
            double min=data[n*i],max=data[n*i];
            for(j=0;j<n;j++)
                {
                    if(min>data[n*i+j])
                        min=data[n*i+j];
                    if(max<data[n*i+j])
                        max=data[n*i+j];
                    avg+=data[n*i+j];
                }
                range=max-min;
            avg/=n;
            gavg+=avg;
            grange+=range;
        }
        double min=data[n*i],max=data[n*i];
        for(i=count,j=0;j<extr;j++)
        {
            avg=0;

            if(min>data[n*i+j])
                min=data[n*i+j];
            if(max<data[n*i+j])
                max=data[n*i+j];
            avg+=data[n*i+j];
            range=max-min;
            avg/=extr;
            gavg+=avg;
            grange+=range;
        }
        gavg=gavg/(ceil(x/n));
        grange=grange/(ceil(x/n));
        double UCL=gavg + (A2*grange);
        double LCL=gavg-(A2*grange);
        double CL=gavg;
        double sigma= fabs((UCL -CL))/3;
       // printf("%lf %lf %lf",UCL,LCL,CL);
        int control=0;
        for(i=0;i<x;i++)
        {
            double temp;
            if(fabs(data[i])>(3*sigma))
            {
                control=1;
                break;
            }
            if(i>=2)
            {
                int gf=0;int po=0,ne=0;int anb=0;
                for(gf=i;gf>=i-2;gf--)
                {

                    double gain=fabs(data[i]);
                    if(gain>2*sigma)
                    {
                        anb++;

                    }
                    if(data[gf]>=CL)
                            po++;
                        else
                            ne++;
                }
                if(po>=2||ne>=2||anb>=2)
                {
                    control=1;
                    break;
                }


            }
            if(i>=4)
            {
                int gf=0;int po=0;int ne=0;int anb=0;
                for(gf=i;gf>=i-4;gf--)
                {
                    double gain=fabs(data[i]);
                    if(gain>sigma)
                    {
                        anb++;

                    }
                    if(data[gf]>=CL)
                            po++;
                        else
                            ne++;
                }
                if(po>=4||ne>=4||anb>=4)
                {
                    control=1;
                    break;
                }
            }
            if(i>=7)
            {
                int gf=0;int po=0;int ne=0;
                for(gf=i;gf>=i-4;gf--)
                {
                    double gain=fabs(data[i]);
                    if(data[gf]>=CL)
                        po++;
                    else
                        ne++;

                }
                if(po>=8)
                {
                    control=1;
                    break;
                }
            }
            }
        //printf("%lf",sigma);
        if(control==0)
        {
            printf("In Control\n");
        }
        else
            printf("Out of Control\n");
    }
    return 0;
}
