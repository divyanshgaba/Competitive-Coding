#include <iostream>
#include <map>
using namespace std;
int n,m;
char s[5000];
char hold[5000];
//string s;
map<string,int> yaad;
int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
/*
int answer(int st,int en)
{
    if(st==n)
        return 0;
    if(st>en)
        return 0;
    if(st==en)
    {
        string ok = "0";
        ok[0]=s[st];
        if(yaad.count(ok)==0)
        {
            yaad.insert(make_pair(ok,0));
            if(GCD(s[st]-'0',m)==1)
                return 1;
        }
        return 0;
    }
    int temp =0;
    string sub = s.substr(st,en-st+1);
    if(yaad.count(sub)==0)
    {
        //cout<<sub<<endl;
        yaad.insert(make_pair(sub,0));
        if(GCD(atoi(sub.c_str()),m)==1)
            temp++;
    }

    return temp + answer(st+1,en) +answer(st,en-1);
}*/
int solve(char str[], int n) {

	int count =0;
	char hold[10000]="";
	int mg=0;
	for(int len = 1; len <= n; len++) {

		for(int i = 0; i <= n - len; i++) {

			int j = i + len - 1;
            mg=0;
			for(int k = i; k <= j; k++) hold[mg++]=str[k];

            hold[mg]='\0';mg=0;
            if(GCD(m,atoi(hold))==1)
                    count++;
		}
	}
	return count;
}

int main()
{
    cin>>n>>m;
    cin>>s;
    int count=0;
    int mg=0;
   // cout<<answer(0,n-1)<<endl;
   /* for(int len = 1; len <= n; len++) {

        for(int i = 0; i <= n - len; i++) {

            int j = i + len - 1;

            for(int k = i; k <= j; k++)
            {
                hold[mg++]=s[k];
            }
            hold[mg]='\0';
            if(GCD(atoi(hold),m)==1)
                    count++;
            mg=0;

        }

    }*/
    int temp=1;
    if(n>1000)
        temp=0;
    cout<<solve(s,n)-temp<<endl;
    return 0;
}
