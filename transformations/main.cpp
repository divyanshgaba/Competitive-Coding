/*
ID: divyans19
PROG: transform
LANG: C++
*/
#include <iostream>
#include<stdbool.h>
#include<vector>
#include<fstream>
using namespace std;
int n;
bool check(vector <vector<char> > &a,vector <vector<char> > &b)
{
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(b[i][j] != a[i][j])
            {
                return false;
            }
        }
    }
    //fout<<"here";
    return true;
}
bool rotate90(vector <vector<char> > &a,vector <vector<char> > &b)
{
    vector <vector<char> > c(n,vector<char>(n));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            c[i][j] = a[n-j-1][i];
        }
    }
  /*  fout<<"90"<<endl;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            fout<<c[i][j];
        }
        fout<<endl;
    }
    fout<<endl;
*/
    return check(b,c);
}
bool rotate180(vector <vector<char> > &a,vector <vector<char> > &b)
{
    vector <vector<char> > c(n,vector<char>(n));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            c[i][j] = a[n-i-1][n-j-1];
        }
    }
    /*fout<<"180"<<endl;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            fout<<c[i][j];
        }
        fout<<endl;
    }
    fout<<endl;
    */
    return check(b,c);
}
bool rotate270(vector <vector<char> > &a,vector <vector<char> > &b)
{
    vector <vector<char> > c(n,vector<char>(n));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            c[i][j] = a[j][n-i-1];
        }
    }
    /*fout<<"270"<<endl;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            fout<<c[i][j];
        }
        fout<<endl;
    }
    fout<<endl;
    */
    return check(b,c);
}
bool mirror(vector <vector<char> > &a,vector <vector<char> > &b)
{
    vector <vector<char> > c(n,vector<char>(n));
    c =a;
    for(int i =0;i<n;i++)
    {
        for(int j =0 ;j<n/2;j++)
        {
            char temp = c[i][j];
            c[i][j] = c[i][n-j-1];
            c[i][n-j-1] =temp;
        }

    }
    /*fout<<"mir"<<endl;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            fout<<c[i][j];
        }
        fout<<endl;
    }
    fout<<endl;
    */
    return check(b,c);
}
bool comb(vector <vector<char> > &a,vector <vector<char> > &b)
{
    vector <vector<char> > c(n,vector<char>(n));
    c =a;
    for(int i =0;i<n;i++)
    {
        for(int j =0 ;j<n/2;j++)
        {
            char temp = c[i][j];
            c[i][j] = c[i][n-j-1];
            c[i][n-j-1] =temp;
        }

    }
    return (rotate180(c,b)||rotate270(c,b)||rotate90(c,b));
}

int main()
{
    ifstream fin("transform.in");  ofstream fout("transform.out");
    fin>>n;
    vector <vector<char> > a(n,vector<char>(n));
    vector <vector<char> > b(n,vector<char>(n));
    char temp;
    for(int i =0;i<n;i++)
    {
        for (int j =0;j<n;j++)
        {
            fin>>temp;
            a[i][j]=temp;
        }
    }
    for(int i =0;i<n;i++)
    {
        for (int j =0;j<n;j++)
        {
            fin>>temp;
            b[i][j]=temp;
        }
    }
    if(rotate90(a,b))
        fout<<"1";
    else if(rotate180(a,b))
        fout<<"2";
    else if(rotate270(a,b))
        fout<<"3";
    else if(mirror(a,b))
        fout<<"4";
    else if(comb(a,b))
        fout<<"5";
    else if(check(a,b))
        fout<<"6";
    else
        fout<<"7";
    fout<<endl;
    return 0;
}
