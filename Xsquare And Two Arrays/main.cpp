#include <iostream>

using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    int a[n],b[n];
    int oa[n],ob[n];
    oa[0]=ob[0]=0;
    cin>>a[1];
    oa[1]=a[1];
    //cout<<oa[1]<<"-- ";

    for(int i =2;i<=n;i++)
    {
        cin>>a[i];
        oa[i] = a[i]+oa[i-2];
        //cout<<oa[i]<<"-- ";

    }
    //cout<<endl;
    cin>>b[1];
    ob[1]=b[1];
    //cout<<ob[1]<<"-- ";
    for(int i =2;i<=n;i++)
    {
        cin>>b[i];
        ob[i] = b[i]+ob[i-2];
        //cout<<ob[i]<<"-- ";


    }
        //cout<<endl;

    for(int i =0;i<q;i++)
    {
        int j,l,r;
        cin>>j>>l>>r;
        int ans =0;
        if(j==1)
        {
           if(r%2==0)
           {
               ans+=ob[r];
               ans+=oa[r-1];
           }
           else
           {
               ans+=oa[r];
               ans+=ob[r-1];
           }
           if(l%2==0)
           {
               ans-=ob[l];
               ans-=oa[l+1];
               ans+=a[l+1];
               ans+=b[l];

           }
           else
           {
               ans-=oa[l];
               ans-=ob[l+1];
               ans+=a[l];
               //cout<<b[l+1]<<"kk"<<endl;
               ans+=b[l+1];
           }

        }
        else
        {
            if(r%2)
           {
               ans+=ob[r];
               ans+=oa[r-1];
           }
           else
           {
               ans+=oa[r];
               ans+=ob[r-1];
           }
           if(l%2)
           {
               ans-=ob[l];
               ans-=oa[l+1];
               ans+=a[l+1];
               ans+=b[l];

           }
           else
           {
               ans-=oa[l];
               ans-=ob[l+1];
               ans+=a[l];
               ans+=b[l+1];
           }

        }
        cout<<ans<<endl;

    }
    return 0;
}
