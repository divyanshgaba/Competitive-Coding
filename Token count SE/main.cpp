#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>
#include <cmath>
using namespace boost;
using namespace std;

int main() {

    cout<<"Enter name of the file to calculate token count for: ";
    string s;
    cin>>s;
    /*ifstream cin(s);*/
	map<string,int> m;
	string line;
	string delim = "	 ,-+*;:><=\'\".{([~!|&";
	char_separator<char> sep("	 ,-+*;:><=.{}()[]~!|&");
	char_separator<char> literals("\"\'");
	while(getline(cin,line))
	{
		for(auto i:line)
		{
			for(auto j:delim)
				if(j == i)
					m[string(1,j)]++;
		}
		tokenizer<char_separator<char>> literaltokens(line,literals);
		int z = 0;
		for (auto tok_iter:literaltokens)
		{
			if(z++&1)
			{
				m[tok_iter]++;
				continue;

			}
			tokenizer<char_separator<char>> tokens(tok_iter, sep);
			for(auto i: tokens)
				m[i]++;

		}
	}

	cout<<"Number of tokens: "<<m.size()<<endl;
	int N = 0;
	for(auto i:m)
	{
		N += i.second;
	}
	cout<<"Number of occurences of tokens: "<<N<<endl;
	cout<<"Volume of program: "<<N*(log(m.size()))<<endl;
	for(auto i:m)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}
