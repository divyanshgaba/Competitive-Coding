#include <stdio.h>
#include <stdlib.h>

int main()
{
    while(!feof(stdin)){

        int a, p,i,j,k,flag=0,temp,size=0,c=1;
        scanf("%d %d",&a,&p);
        int *form[p];
        for (i=0; i<p; i++)
             form[i] = (int *)malloc(p * sizeof(int));

        // Note that form[i][j] is same as *(*(form+i)+j)

        for (i = 0; i <  p; i++)
          for (j = 0; j < p; j++)
             form[i][j] = 0;
        for(i=1;i<=p;i++)
        {

            scanf("%d",&temp);

            if(i==1 && temp==0)
            {
                form[0][0]=1;
                size++;

            }
            else if(temp==0)
            {
                for(j=0;form[0][j]!=0;j++);
                form[0][j]=i;
            }
            else
            {
                flag=0;

                for(j=0;j<p;j++)
                {
                    for(k=0,c=1;form[k][j]!=0;k++,c++)
                    {

                        if(form[k][j]==temp)
                        {
                            form[k+1][j]=i;
                            flag=1;
                            break;
                        }

                    }

                    if(flag==1)
                    {

                        break;
                    }

                }

            }
            if(size<c+1)
                size=c+1;

        }
    if(feof(stdin))
        break;
    printf("%d\n",abs(a-size));
    }
    return 0;
}
