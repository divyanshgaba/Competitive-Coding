#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int getMid(int s, int e) {  return s + (e -s)/2;  }

int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];

    if (se < qs || ss > qe)
        return -1;

    int mid = getMid(ss, se);
    return max(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

int RMQ(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  max(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;

    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}



int main()
{
	fast;
	int n,k,p;
	cin>>n>>k>>p;
	int a[2*n],sum[2*n];
	for(int i =0;i<n;i++)
        cin>>a[i],a[i+n]=a[i];
    sum[0]=a[0];
    for(int i =1;i<2*n;i++)
    {
        sum[i] = sum[i-1]+a[i];
    }
    int seg[2*n];
    memset(seg,0,sizeof(seg));
	for(int i =2*n-1;i>=0;i--)
    {
        if(i!=0)
            seg[i] = -sum[i-1];
        if(i + k- 1 < 2*n)
            seg[i] += sum[i+k-1];
        else
            seg[i]+=sum[2*n-1];

    }

    /*for(int i =0;i<2*n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i =0;i<2*n;i++)
        cout<<sum[i]<<" ";
    cout<<endl;
    for(int i =0;i<2*n;i++)
        cout<<seg[i]<<" ";
    cout<<endl;*/
    string s;
    cin>>s;
    if(k>=n)
    {
        for(auto i:s)
        {
            if(i=='?')
                cout<<sum[n-1]<<endl;
        }
        return 0;
    }
    int *st =constructST(seg,2*n);
    int j =n;
    for(int i =0;i<p;i++)
    {
        if(s[i] == '!')
        {
            j--;
            if(j==0)
                j=n;
        }
        else
        {
            cout<<RMQ(st,2*n,j,j+n-k)<<endl;
        }
    }
	return 0;

}
