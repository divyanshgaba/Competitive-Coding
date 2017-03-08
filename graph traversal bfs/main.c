#include <stdio.h>
#include <stdlib.h>
int a[20][20],q[20],inserted[20],n,f=0,r=-1,j=0;
void bfs(int v)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[v][i]&&!inserted[i])
            q[++r]=i;
    }
    if(j<=r)
    {
        inserted[q[j]]=1;
        bfs(q[j++]);
    }
}
int main()
{
    int v,i,j;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        q[i]=0;
        inserted[i]=0;
    }
    printf("Enter Graph in Matrix form\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int ch=1;
    while(ch!=0){
            system("cls");
    printf("Enter sorting vector: ");
    scanf("%d",&v);
    bfs(v-1);
    printf("\nNodes Reachable are:\t");
    for(i=0;i<n;i++)
    {
        if(inserted[i])
            printf("%d\t ",i+1);
    }
    getch();
    scanf("%d",ch);
    }
    return 0;
}
