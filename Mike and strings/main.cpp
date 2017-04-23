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
void computeLPSArray(const char *pat, int M, int *lps);
int KMPSearch(const char *pat, const char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    //cout<<pat<<endl;
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j  = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            return i-j;
            //printf("Found pattern at index %d \n", i-j);
            j = lps[j-1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return -1;
}
void computeLPSArray(const char *pat, int M, int *lps)
{
    int len = 0;

    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];

            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
	fast;
	int n;
	cin>>n;
	char s[51][51];
	for(int i =0;i<n;i++)
        cin>>s[i];
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    char pat[101];
    strcpy(pat,s[0]);
    strcat(pat,s[0]);
    //cout<<pat<<endl;
    for(int i =0;i<n;i++)
    {
        int temp = KMPSearch(s[i],pat);
        if(temp == -1)
        {
            cout<<-1<<endl;
            //cout<<s[i]<<" "<<i<<endl;
            return 0;
        }
    }
    int len = strlen(s[0]);
    int answer = 1e9;
    for(int i =0;i<n;i++)
    {
        strcpy(pat,s[i]);
        strcat(pat,s[i]);
        int ans  = 0;
        for(int j =0;j<n;j++)
        {
            int temp = KMPSearch(s[j],pat);
            if(temp!=0)
                ans+=(len-temp);
            //cout<<pat<<" "<<s[j]<<" "<<KMPSearch(s[j],pat)<<endl;
        }
        if(answer>ans)
        {
            //cout<<pat<<endl;
            answer = ans;
        }
        //answer = min(answer,ans);
    }
    cout<<answer<<endl;
	return 0;

}
