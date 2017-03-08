
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<stdbool.h>
#include<list>

using namespace std;
#include <stdlib.h>


int n,w[100],k,x[501],c[501];
bool c_[501];
int ik;
using namespace std;

int search(int arr[],int key)
{
    int low=0,high=n-1,mid=-1;
    bool flag=false;

    while(low<high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key){
            flag=true;
            break;
        }
        else if(arr[mid]<key)
            low=mid+1;
        else
            high=mid;

    }
    if(flag)
        return mid;
    else{
        if(low>=n-1)
            return -1;
        else
        return high;
        //high will give next smaller
    }
}


void print( list<int> l){
    int sum=0;
    for(list<int>::iterator it=l.begin(); it!=l.end() ; ++it)
            {sum+=*it;
            }
    if(sum == c[ik])
        c_[ik]=true;

}

void subset(int arr[], int size, int left, int index, list<int> &l){
    if(c_[ik]==true)
        return;
    if(left==0){
        print(l);
        return;
    }
    for(int i=index; i<size;i++){
        l.push_back(arr[i]);
        subset(arr,size,left-1,i+1,l);
        l.pop_back();
    }

}

int main()
{
    int test;
    cin>>test;
    list<int> lt;
    while(test--)
    {
        int fake[500];
        cin>>n;
        for(ik=0;ik<n;ik++)
            {cin>>w[ik];
                fake[ik]=w[ik];
            }
        cin>>k;
        for(ik=0;ik<k;ik++)
            {cin>>x[ik];
                c_[ik] =false;
            }
        sort(w,w+n);
        sort(fake,fake+n);
        reverse(fake,fake+n);
        for(ik = 0 ;ik <k;ik++)
        {
            cin>>c[ik];
            int temp = search(w,c[ik]);
                if(x[ik]==1&& c[ik] == w[temp])
                c_[ik]=true;
                else
                subset(fake,n,x[ik],temp,lt);
             if(c_[ik])
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }

    }
    return 0;
}
