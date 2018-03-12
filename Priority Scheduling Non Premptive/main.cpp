#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1e9;
struct node
{
	int arrival, burst, prior;
	int wait, turnaround;
	bool completed;
	int executed;
	node()
	{
		executed=arrival=burst=prior=wait=turnaround=completed=0;
	}
};
bool cmp(node a, node b)
{
	if(a.prior != b.prior)
		return a.prior < b.prior;
	else return a.arrival < b.arrival;
}
int main()
{
	int n;
	cout<<"Enter number of processes: ";
	cin>>n;
	node p[n];
	for(int i = 0;i<n;i++)
	{
		cout<<"Process #"<<i<<endl;
		cout<<"\tArrival Time: ";
		cin>>p[i].arrival;
		cout<<"\tBurst Time: ";
		cin>>p[i].burst;
		cout<<"\tPriority: ";
		cin>>p[i].prior;
	}
	int cur = 0;
	double avg_wait=0, avg_turn = 0;
	for(int i = 0;i<n;i++)
	{
		int min_prior = 1e9;
		int min_arr = 1e9;
		int process = -1;
		for(int j = 0;j<n;j++)
		{
			if(p[j].completed)
				continue;
			min_arr = min(min_arr, p[j].arrival);
		}
		cur = max(cur, min_arr);
		for(int j = 0;j<n;j++)
		{
			if(p[j].completed)
				continue;
			if(p[j].arrival <= cur)
			{
				if(p[j].prior < min_prior)
					min_prior = min(min_prior, p[j].prior), process = j;
				else if(p[j].prior == min_prior)
				{
					if(p[j].arrival < p[process].arrival)
						min_prior = min(min_prior, p[j].prior), process = j;
					else if(p[j].arrival == p[process].arrival)
					{
						if(p[j].burst -p[j].executed < p[process].burst-p[process].executed)
						{
							min_prior = min(min_prior, p[j].prior), process = j;
						}
					}

				}
			}
		}
		p[process].wait = cur -  p[process].arrival;
		cur += p[process].burst;
		p[process].completed = true;
		p[process].turnaround = p[process].wait + p[process].burst;
		avg_wait += p[process].wait;
		avg_turn += p[process].turnaround;
	}
	for(int i = 0;i<n;i++)
	{
		cout<<"Process #"<<i<<" Wait time: "<<p[i].wait<<" Turnaround time: "<<p[i].turnaround<<endl;
	}
	avg_wait/=n;
	avg_turn/=n;
	cout<<"Average Waiting time: "<<avg_wait<<endl;
	cout<<"Average Turnaround time: "<<avg_turn<<endl;

	return 0;
}
