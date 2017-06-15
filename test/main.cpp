#include <iostream>
using namespace std;

void make_palin(char *v,char *s,int len){
	int hi = len-1;
	int lo = 0;

	while(lo <= hi){
		v[lo] = s[lo];
		v[hi] = s[lo];
		lo++;
		hi--;
	}
}

int main(){
	int T;
	string in;

	cin >> T;

	for(int t=0;t<T;t++){
		cin >> in;

		char out[in.size()];
		int i=0,len=in.size();
		while(in[i]!='\0'){
			if(in[i]!='9') break;
			i++;
		}

		if(in[i]=='\0'){
			for(int j=0;j<i+1;j++){cout << '1';}
			cout << endl;
			continue;
		}

		if(len==1){
			cout << (char)(in[0]+1) << endl;
			continue;
		}

		make_palin(&out[0],&in[0],len);

		float mid=(1.0*len)/2;
		bool flag=0;

		int lo=(int)(mid-1);
		int hi=(int)(mid+1);
		if(len%2==0) hi--;

		while(lo>-1){
			if(in[lo] < in[hi]){
				flag=1;
				break;
			}
			else if(in[lo] > in[hi]) break;
			lo--;hi++;
		}

		if(lo==-1 || flag){
				if(len%2==0){
					hi=len/2;lo=hi-1;
				}
				else {
					hi=(len-1)/2;lo=hi;
				}

				while(out[lo]=='9'){
					out[hi] = '0';
					out[lo] = '0';
					hi++;lo--;
				}

				out[lo] += 1;
				out[hi] = out[lo];
		}

		cout << out << endl;
	}
}
