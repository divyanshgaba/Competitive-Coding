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

int s[401][401];
bool done[401][401][401];
int SolveMagicSquare(vector < vector < int > > mat)
{
	int n2 = mat.size();
	int n = sqrt(n2);
	int x=0;
	if(mat[0][0]>1)
        return 0;
    else
    {
        mat[0][0]=1;
    }
	for(int i =1;i<=n2;i++)
        x^=i;
    for(int i =0;i<n2;i++)
        for(int j =0;j<n2;j++)
                s[i][j] = x;
    for(int i =0;i<n2;i+=n)
    {
        for(int j =0;j<n2;j+=n)
        {
            for(int k =0;k<n;k++)
            {
                for(int l =0;l<n;l++)
                {
                    int tmp = mat[i+k][j+l];
                    if(!tmp)
                        continue;
                    done[i+k][j+l][tmp] =true;
                    for(int m =0;m<n2;m++)
                    {
                        if(!done[i+k][m][tmp])
                        {
                            done[i+k][m][tmp]=true;
                            s[i+k][m]^=tmp;
                        }
                        if(!done[m][j+k][tmp])
                        {
                            done[m][j+l][tmp]=true;
                            s[m][j+l]^=tmp;
                        }
                    }
                    for(int m =0;m<n;m++)
                    {
                        for(int h =0;h<n;h++)
                        {
                            if(!done[m+i][h+j][tmp])
                                done[m+i][h+j][tmp]=true,s[m+i][h+j]^=tmp;
                        }
                    }
                }
            }
        }
    }
    int flag =1;
    for(int i =0;i<n2&&flag;i++)
        for(int j =0;j<n2&&flag;j++)
            if(!s[i][j])
                flag=0;
    if(flag)
        return 1;
    else
        return 0;

}

int main()
{
    int output;
    int ip1_rows = 0;
    int ip1_cols = 0;
    cin >> ip1_rows >> ip1_cols;
    vector< vector < int > > ip1(ip1_rows);
    for(int ip1_i=0; ip1_i<ip1_rows; ip1_i++) {
        for(int ip1_j=0; ip1_j<ip1_cols; ip1_j++) {
            int ip1_tmp;
            cin >> ip1_tmp;
            ip1[ip1_i].push_back(ip1_tmp);
        }
    }
    output = SolveMagicSquare(ip1);
    cout << output << endl;
    return 0;
}
