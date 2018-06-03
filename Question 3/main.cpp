
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second


using namespace std;

typedef pair<int,int> pi;


int main()
{
	int test=1;
	scanf("%d\n",&test);
	while(test--)
    {
        string line;
        getline(cin,line);
		stringstream input(line);
		string str;
		int x,y;
		x=y=0;
		while(input>>str)
        {
            int count = stoi(str.substr(1));
            switch(str[0])
            {
                case 'N':
                    y+=count;
                    break;
                case 'S':
                    y-=count;
                    break;
                case 'W':
                    x+=count;
                    break;
                case 'E':
                    x-=count;
                    break;
            }
        }
    }
	return 0;

}
