#include<iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;
typedef long long ll;
void freq(ll n,ll a[]){
    while(n){
        a[n%10]++;
        n/=10;
    }
}
ll all(ll a[]){
    ll ans=0;
    for(ll i=0;i<10;i++){
        if(a[i]) ans++;
    }
    return ans;
}
int main() {
    ll t,pointer=0;
    cin>>t;
    while(t--){
        ll n,x=1;
        cin>>n;
        ll zer=0;
        if(n == 0){
            cout<<"LOSE\n";
            continue;
        }
        while(n%10 == 0) {
            n/=10;
            zer++;
        }

        ll a[10];
        memset(a,0,sizeof(a));
        if(zer>0) a[0]=1;
        ll ans = 0;
        while(all(a) != 10){
            ans = x*n;
            freq(x*n,a);
            ++x;
        }
        cout<<ans;
        while(zer--) cout<<0;
        cout<<endl;
    }
    return 0;
}
