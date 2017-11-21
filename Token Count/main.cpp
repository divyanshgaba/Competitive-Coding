/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
	ifstream fin("input.c");
	char s[256];
	char* delim = ",.  /\\\'{}();:+-*%=><    \t";
	map<string,int> m;
	while(fin.getline(s,256))
    {
        //cout<<"here1"<<s<<" "<<strlen(s)<<endl;
        int n = strlen(s);
        for(int i = 0;i<n-1;i++)
        {
            if(s[i]=='/'&&s[i+1]=='/')
            {
                s[i]='\0';
                //s[i+1]='\0';
                break;
            }
        }
        //cout<<"here2"<<s<<" "<<strlen(s)<<endl;
        char *token = strtok(s,"\"");
        string k;
        while(token!=NULL)
        {
            k+=string(token);
            token = strtok(NULL,"\"");
            if(token!=NULL)
                m[string(token)]++, token = strtok(NULL,"\"");
        }
        //cout<<"here3"<<s<<" "<<strlen(s)<<endl;
        token = strtok((char*)(k.c_str()),delim);
        while(token!=NULL)
        {
            m[string(token)]++;
            token = strtok(NULL,delim);
        }
        //cout<<"here4"<<s<<" "<<strlen(s)<<endl;
    }
    for(auto i:m)
        cout<<i.F<<" "<<i.S<<endl;
	return 0;

}
