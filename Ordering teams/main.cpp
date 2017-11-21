#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--)
    {
        int a[3][3];
        for(int i = 0;i<3;i++)
            for(int j = 0;j<3;j++)
                cin>>a[i][j];
        bool ans = true;
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                if(i==j)
                    continue;
                bool temp = false;
                if(a[i][0]<=a[j][0]&&a[i][1]<=a[j][1]&&a[i][2]<=a[j][2])
                {
                    if(a[i][0]<a[j][0]||a[i][1]<a[j][1]||a[i][2]<a[j][2])
                        temp = true;
                }
                if(a[j][0]<=a[i][0]&&a[j][1]<=a[i][1]&&a[j][2]<=a[i][2])
                {
                    if(a[j][0]<a[i][0]||a[j][1]<a[i][1]||a[j][2]<a[i][2])
                        temp = true;
                }
                ans = ans&&temp;
            }
        }
        if(ans)
            cout<<"yes\n";
        else
            cout<<"no\n";
	}
	return 0;
}
