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
    srand(time(NULL));
	fast;
	int n = 5;
	cout<<n<<endl<<n<<endl;
	int cn = 0;
	for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int temp=rand()%3;
            if(temp == 2){
                if(cn<11){
                    cout<<temp<<" ";
                    cn++;
                }
                else{
                    j--;
                    continue;

                }
            }
            else if(temp == 1){
                j--;
                continue;
            }
            else{
                cout<<temp<<" ";
            }
        }
        cout<<endl;
	}
	cout<<rand()%n<<endl<<rand()%n<<endl;
	return 0;

}
