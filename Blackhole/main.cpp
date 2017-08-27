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

struct node
{
    double x,y,z;
};

int main()
{
	//ifstream cin("input.in");
	//ofstream cout("output.out");

	int test=1;
	cin>>test;
	for(int t = 1;t<=test;t++)
    {
		node A,B,C;
		cin>>A.x>>A.y>>A.z;
		cin>>B.x>>B.y>>B.z;
		cin>>C.x>>C.y>>C.z;
		double a = sqrt(pow(B.x-C.x,2) + pow(B.y-C.y,2) + pow(B.z-C.z,2));
		double b = sqrt(pow(C.x-A.x,2)+pow(C.y-A.y,2)+pow(C.z-A.z,2));
		double c = sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2) + pow(A.z-B.z,2));
		double cx = (a*A.x + b*B.x + c*C.x)/(a+b+c);
        double cy = (a*A.y + b*B.y + c*C.y)/(a+b+c);
        double cz = (a*A.z + b*B.z + c*C.z)/(a+b+c);

        double mag = sqrt(pow(A.x-cx,2) + pow(A.y-cy,2) + pow(A.z-cz,2))/2;
        cout<<fixed<<setprecision(10)<<"Case #"<<t<<": "<<mag<<endl;
    }
	return 0;

}
