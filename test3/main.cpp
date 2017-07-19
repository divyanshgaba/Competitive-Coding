#include<bits/stdc++.h>
using namespace std;
int i,j,k,x,T,n,m,CJindex[1001],flag=1, flag2=5,jobChef[1001],jobAss[1001];
int main()
{
    ifstream fin("input.txt");
    ofstream cout("output.out");
    fin>>T;
	for(i=0;i<T;i++)
	{
	    memset(jobAss,0,sizeof(jobAss));
	    memset(jobChef,0,sizeof(jobChef));
	    memset(CJindex,0,sizeof(CJindex));

		flag2=5;
		fin>>n>>m;
		for(j=1;j<=m;j++)
		{
			fin>>CJindex[j];
		}
		for(j=1; j<=n;j++)
		{
			for(x=1;x<=m;x++)
			{	if(j==CJindex[x])
				{
					flag=0;
					jobChef[j]=0;
					jobAss[j]=0;
					break;
				}

			}
			if(flag==0)
			{
				flag=1;
				continue;
			}
			if(flag2==5)
			{
				jobChef[j]=j;
				flag2=1;
				continue;
			}
			if(flag!=0)
			{
				if(flag2==0)
				{
					jobChef[j]=j;
					flag2=1;
				}
				else
				{
					 if(flag2==1)
					{
						jobAss[j]=j;
						flag2=0;
					}
				}
			}
		}
		for(k=1;k<=n;k++)
		{
			if(jobChef[k]!=0)
                cout<<jobChef[k]<<" ";
		}
		cout<<"\n";
		for(k=1;k<=n;k++)
		{
			if(jobAss[k]!=0)
				cout<<jobAss[k]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
