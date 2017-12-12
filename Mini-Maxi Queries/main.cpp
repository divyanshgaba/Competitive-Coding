#include<iostream>
using namespace std;
const int N = 5e4 + 1;
int arr[N];
int main()
{
	int n,q;
    scanf("%d %d",&n,&q);
	while(q--)
    {
        int t,l,r,val;
        scanf("%d",&t);
        if(t==1)
        {
            cin>>l>>r>>val;
            for(int i = l;i<=r;i++)
                arr[i]^=val;
        }
        else if(t ==3)
        {
            scanf("%d %d",&l,&r);
            int i,j;
            i=-1,j=-1;
            for(int k = l;k<=r;k++)
            {
                if(arr[k]==1)
                {
                    i=k;
                    break;
                }
            }
            for(int k = r;k>i;k--)
            {
                if(arr[k]==1)
                {
                    j=k;
                    break;
                }
            }
            if(i==-1||j==-1)
                printf("-1\n");
            else
                printf("%d\n",j-i);

        }
        else
        {
            scanf("%d %d",&l,&r);
            int best = 1e9;
            int i;
            for(i = l;i<=r;i++)
            {
                if(arr[i]==1)
                    break;
            }
            for(int j = i+1;j<=r;j++)
            {
                if(arr[j]==1)
                {
                    if(best>j-i)
                        best=j-i;
                    i=j;
                }
            }
            if(best<1e9)
                printf("%d\n",best);
            else
                printf("-1\n");
        }
    }
	return 0;

}
