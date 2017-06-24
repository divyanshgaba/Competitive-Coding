#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

#define mp(i,j) make_pair(i,j)

int fact[1000007];

vector<int> tmp;
struct node{
vector<pair<int,int> >pr;
int size;
};

class QTree{
int n,sz;
int *arr;
node *tree;
void sieve(int n=1000001){
int x = (int)sqrt(n)+1;
for(int i=2;i<=n;i++){
if(!fact[i]){
fact[i]=i;
if(i<=x){
for(int j=i*i;j<=n;j+=i){
if(!fact[j])
fact[j]=i;
}
}
}
}
}
void construct(int s,int e,int idx){
if(s==e){
copy(idx,s);
return;
}
int mid = (s+e)/2;
construct(s,mid,2*idx);
construct(mid+1,e,2*idx+1);
merge(idx);
}
void copy(int idx,int x){
int y=arr[x];
while(fact[y]){
tmp.push_back(fact[y]);
y/=fact[y];
}
sort(tmp.begin(),tmp.end());
tree[idx].size = 0;
for(vector<int>::iterator it=tmp.begin();it!=tmp.end();it++){
if(!tree[idx].size||tree[idx].pr.back().first!=(*it)){
tree[idx].pr.push_back(mp(*it,1));
tree[idx].size+=1;
}
else
tree[idx].pr.back().second+=1;
}
tmp.clear();
}
void merge(int idx){
int lnode=2*idx,rnode = 2*idx+1,i=0,j=0;
tree[idx].size=0;
while(i<tree[lnode].size && j<tree[rnode].size){
if(tree[lnode].pr[i].first==tree[rnode].pr[j].first){
tree[idx].pr.push_back(mp(tree[lnode].pr[i].first,tree[lnode].pr[i].second+tree[rnode].pr[j].second));
i++;j++;
}
else if(tree[lnode].pr[i].first < tree[rnode].pr[j].first){
tree[idx].pr.push_back(mp(tree[lnode].pr[i].first,tree[lnode].pr[i].second));
i++;
}
else{
tree[idx].pr.push_back(mp(tree[rnode].pr[j].first,tree[rnode].pr[j].second));
j++;
}
tree[idx].size+=1;
}
while(i<tree[lnode].size){
tree[idx].pr.push_back(mp(tree[lnode].pr[i].first,tree[lnode].pr[i].second));
tree[idx].size+=1;
i++;
}
while(j<tree[rnode].size){
tree[idx].pr.push_back(mp(tree[rnode].pr[j].first,tree[rnode].pr[j].second));
tree[idx].size+=1;
j++;
}
}
public:
QTree(int *arr,int n){
this->n=n;
this->arr=arr;
sieve();
cout<<"here"<<endl;
sz = 2*(int)pow(2,(int)ceil(log2(n) ) )+1;
tree = new node[4*n];
construct(0,n-1,1);
cout<<"here2"<<endl;
for(int i=0;i<sz;i++){
for(int j=1;j<tree[i].size;j++){
tree[i].pr[j].second+=tree[i].pr[j-1].second;
}
}
cout<<"here3"<<endl;
// for(int i=0;i<sz;i++){
// for(int j=0;j<tree[i].size;j++){
// if(tree[i].pr[j].first<=1 ||tree[i].pr[j].second<1){
// cout<<tree[i].pr[j].first<<"\t"<<tree[i].pr[j].second<<"\n";
// }
// }
// }
}
static bool cmp(pair<int,int>a,pair<int,int>b){
return a.first < b.first;
}

int query(int l,int r,int s, int e,int x,int y, int idx=1){
if(l>e||r<s)
return 0;
if(l<=s&&r>=e){
int lb = lower_bound(tree[idx].pr.begin(),tree[idx].pr.end(),mp(x,0),cmp)-tree[idx].pr.begin()-1;
int ub = upper_bound(tree[idx].pr.begin(),tree[idx].pr.end(),mp(y,0),cmp)-tree[idx].pr.begin()-1;
return tree[idx].pr[ub].second - (lb<0?0:tree[idx].pr[lb].second);
}
int mid = (s+e)/2;
return query(l,r,s,mid,x,y,2*idx)
+query(l,r,mid+1,e,x,y,2*idx+1);
}
};

int main() {
    ofstream cout("output.txt");

int n,a[100009],q,l,r,x,y;
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];
QTree tree=QTree(a,n);
// return 0;
cin>>q;
while(q--){
cin>>l>>r>>x>>y;
cout<<tree.query(l-1,r-1,0,n-1,x,y,1)<<"\n";
}
return 0;
}
