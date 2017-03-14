#include <iostream>

using namespace std;

int main()
{
    int n,cnt;
    int ans = 0;
    cin>>n>>cnt;
        int hold = n;

    int a[cnt];
    for(int i =0;i<cnt;i++)
        cin>>a[i];
    for(int i =0;i<cnt;i++)
    {

        //cout<<n<<" ";
        if(n<5)
        {

            ans+=(hold-n);
            n=hold;
        }
        n=n-a[i];

    }
    cout<<ans<<endl;
    return 0;
}
