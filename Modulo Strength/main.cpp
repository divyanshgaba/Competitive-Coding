#include<iostream>
using namespace std;long n,k,i,j,a[99999],m,s;main(){cin>>n>>k;while(i++<n){cin>>j;a[j%k]++;}while(m<k)s+=a[m]--*a[m++];cout<<s;}
