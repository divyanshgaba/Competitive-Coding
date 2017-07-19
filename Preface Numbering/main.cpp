/*
ID: divyans19
PROG: preface
LANG: C++11
*/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

string roman(int p)
{
    if (!p) return "";
    if(p<10)
    {
        switch(p)
        {
            case 1: return "I";
            case 2: return "II";
            case 3: return "III";
            case 4: return "IV";
            case 5: return "V";
            case 6: return "VI";
            case 7: return "VII";
            case 8: return "VIII";
            case 9: return "IX";
        }
    }
    else if(p < 100)
    {
        switch(p/10)
        {
            case 1: return "X" + roman(p%10);
            case 2: return "XX"+ roman(p%10);
            case 3: return "XXX"+ roman(p%10);
            case 4: return "XL"+ roman(p%10);
            case 5: return "L"+ roman(p%10);
            case 6: return "LX"+ roman(p%10);
            case 7: return "LXX"+ roman(p%10);
            case 8: return "LXXX"+ roman(p%10);
            case 9: return "XC"+ roman(p%10);

        }
    }
    else if(p<1000)
    {
        switch(p/100)
        {
            case 1: return "C" + roman(p%100);
            case 2: return "CC"+ roman(p%100);
            case 3: return "CCC"+ roman(p%100);
            case 4: return "CD"+ roman(p%100);
            case 5: return "D"+ roman(p%100);
            case 6: return "DC"+ roman(p%100);
            case 7: return "DCC"+ roman(p%100);
            case 8: return "DCCC"+ roman(p%100);
            case 9: return "CM"+ roman(p%100);
        }
    }
    else
    {
        switch(p/1000)
        {
        case 1: return "M" + roman(p%1000);
        case 2: return "MM" + roman(p%1000);
            case 3: return "MMM" + roman(p%1000);
        }
        return "";
    }
}


string toroman(int n)
{
    string r = "";
    if(n>999)
    {
        r +=roman(n/1000 * 1000); n%=1000;
    }
    if(n>99)
    {
        r += roman(n/100 * 100);
        n%=100;
    }
    if(n>9)
    {
        r+= roman(n/10 * 10);
        n%=10;
    }
    r += roman(n);
    return r;
}

int cnt[10];
void count(string str)
{
    for(auto i : str)
    {
        if(i == 'I') cnt[0]++;
        if(i == 'V') cnt[1]++;
        if(i == 'X') cnt[2]++;
        if(i == 'L') cnt[3]++;
        if(i == 'C') cnt[4]++;
        if(i == 'D') cnt[5]++;
        if(i == 'M') cnt[6]++;
    }
}

int main()
{
	//fast;
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	int n;
	fin>>n;
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        string s = toroman(i);
        count(s);
    }
    for(int i = 0;i<7;i++)
    {
        if(cnt[i])
        {
            if(i == 0) fout<<"I"<<" "<<cnt[i]<<endl;
            if(i == 1) fout<<"V"<<" "<<cnt[i]<<endl;
            if(i == 2) fout<<"X"<<" "<<cnt[i]<<endl;
            if(i == 3) fout<<"L"<<" "<<cnt[i]<<endl;
            if(i == 4) fout<<"C"<<" "<<cnt[i]<<endl;
            if(i == 5) fout<<"D"<<" "<<cnt[i]<<endl;
            if(i == 6) fout<<"M"<<" "<<cnt[i]<<endl;
        }
    }
	return 0;

}
