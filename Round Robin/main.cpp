#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout<<"Enter number of process: ";
	cin>>n;
	int arr[n],burst[n];
	for(int i = 0;i<n;i++)
    {
        cout<<"Process #"<<i+1<<endl;
        cout<<"\tArrival time: ";
        cin>>arr[i];
        cout<<"\tBurst time: ";
        cin>>burst[i];
    }
    int quantum;
    cout<<"Enter quantum time: ";
    cin>>quantum;
    assert(quantum>0);
    int wait[n],turnaround[n],executed[n],completion[n];
    memset(executed,0,sizeof(executed));
    int cur = 0;
    int completed = 0;
    int last_process = -1;
    while(completed!=n)
    {
        bool found = false;
        int min_time = INT_MAX;
        int process = -1;
        for(int i = last_process+1;i<n;i++)
        {
            if(cur>=arr[i] && executed[i]<burst[i])
            {
                found = true;
                process = i;
                break;
            }
            else if(executed[i]<burst[i])
            {
                min_time = min(min_time,arr[i]);
            }
        }
        for(int i = 0;i<last_process&&!found;i++)
        {
            if(cur>=arr[i] && executed[i]<burst[i])
            {
                found = true;
                process = i;
                break;
            }
            else if(executed[i]<burst[i])
            {
                min_time = min(min_time,arr[i]);
            }
        }
        if(!found)
            cur = min_time;
        else
        {
            cur =  cur + min(burst[process]-executed[process],quantum);
            executed[process] = executed[process] + min(burst[process]-executed[process],quantum);
            last_process = process;
            if(executed[process]==burst[process])
            {
                completed++;
                completion[process] = cur;
            }

        }
    }
    double avg_wait = 0, avg_turnaround = 0;
    for(int i = 0;i<n;i++)
    {
        turnaround[i] = completion[i] - arr[i];
        wait[i] = turnaround[i]-arr[i] -burst[i];
        avg_wait += wait[i];
        avg_turnaround += turnaround[i];
    }
    for(int i = 0;i<n;i++)
    {
        cout<<"Process #"<<i+1<<endl;
        cout<<"\tTurn around time: \t"<<turnaround[i]<<endl;
        cout<<"\tWait time: \t\t"<<wait[i]<<endl;
    }
    avg_wait/=n;
    avg_turnaround/=n;
    cout<<"Average wait time: \t\t"<<avg_wait<<endl;
    cout<<"Average turnaround time: \t"<<avg_turnaround<<endl;

	return 0;

}
