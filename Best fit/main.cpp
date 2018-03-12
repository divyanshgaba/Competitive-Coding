#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout<<"Enter number of process: ";
	cin>>n;
	int process_size[n];
	cout<<"Enter sizes of process: \n";
	for(int i = 0;i<n;i++)
    {
        cout<<"Process #"<<i+1<<endl;
        cout<<"\tSize: ";
        cin>>process_size[i];
    }
    int m;
    cout<<"Enter number of blocks: ";
    cin>>m;
    int block_size[n];
	cout<<"Enter sizes of blocks: \n";
	for(int i = 0;i<m;i++)
    {
        cout<<"block #"<<i+1<<endl;
        cout<<"\tSize: ";
        cin>>block_size[i];
    }
    int assigned_block[n];
    memset(assigned_block,~0,sizeof(assigned_block));
    for(int i = 0;i<n;i++)
    {
        int block = -1;
        int min_size = INT_MAX;
        for(int j = 0;j<m;j++)
        {
            if(block_size[j] >= process_size[i])
            {
                if(min_size>block_size[j])
                    min_size=block_size[j],block = j;
            }
        }
        if(block!=-1)
            block_size[block]-=process_size[i],assigned_block[i]=block+1;;

    }
    for(int i = 0;i<n;i++)
    {
        cout<<"Process#"<<i+1<<endl;
        if(assigned_block[i]!=-1)
            cout<<"\tBlock assigned: "<<assigned_block[i]<<endl;
        else
            cout<<"\tBlock assigned: "<<"not assigned"<<endl;
    }
	return 0;

}
