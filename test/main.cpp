#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool arr[100000];
int shift_result[100000];

class myclass{
public:
	int first,second;
}myvector[100000];

inline bool compare(myclass a,myclass b){
	return (a.first < b.first);
}

inline void store_count(const int k,const int n,int base){

	myvector[0].first = base;
	myvector[0].second = 0;
	for(int i=1;i<n;i++){
		myvector[i].first = myvector[i-1].first + arr[(i+k-1)%n] - arr[i-1];
		myvector[i].second = i;
	}
}

inline bool check(int a,int i,int diff,int n){
	int r=(diff+i);
    if(r>n)
        r%=n;
	if(i>r){
		if(r<a && a<i) return 0;
		else return 1;
	}
	if(i-1<a && a<r+1) return 1;
	else return 0;
}

inline void store_result(const int k,const int n){
	int y=n-k;

	sort(myvector,myvector+n,compare);

	int j=0;
	for(int i=0;i<n;i++){
		for(j=n-1;j>-1;j--){
			if(check(myvector[j].second,i,y,n)) break;
		}
		if(j>-1) shift_result[i]=(myvector[j].first);
	}

	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,K,P;
	char s;

	cin >> N >> K >> P;

	if(K>N) K=N;

 	int base=0;
	for(int i=0;i<N;i++){
		cin >> arr[i];
		if(i<K) base += arr[i];
	}

	store_count(K,N,base);
	store_result(K,N);

	int shiftamount=0,sh;
	for(int i=0;i<P;i++){
		cin >> s;
		if(s == '?'){
			sh = shiftamount % N;
			cout << shift_result[(N-sh)%N] << "\n";
		}
		else{
			shiftamount++;
		}
	}
}
