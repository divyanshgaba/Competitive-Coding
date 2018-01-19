#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 201000
#define SH 200005
int AN;
int A[256 * MAXN + 100];
int cnt[260*MAXN + 1]; // Should be >= 256*MAXN
int SA[256*MAXN + 1];
int freq[256];
/* Used by suffix_array. */
void radix_pass(int* A, int AN, int* R, int RN, int* D) {
   memset(cnt, 0, sizeof(int) * (AN + 1));
   int* C = cnt + 1;
   for(int i = 0; i < RN; i++) ++C[A[R[i]]];
   for(int i = -1, v = 0; i <= AN && v < RN; v += C[i++]) swap(v, C[i]);
   for(int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];
}
/* DC3 in O(N) using 20N bytes of memory.  Stores the suffix array of the string
* [A,A+AN) into SA where SA[i] (0<=i<=AN) gives the starting position of the
* i-th least suffix of A (including the empty suffix).
*/
void suffix_array(int* A, int AN) {
   // Base case... length 1 string.
   if(!AN) {
       SA[0] = 0;
   } else if(AN == 1) {
       SA[0] = 1; SA[1] = 0;
       return;
   }
   // Sort all strings of length 3 starting at non-multiples of 3 into R.
   int RN = 0;
   int* SUBA = A + AN + 2;
   int* R = SUBA + AN + 2;
   for(int i = 1; i < AN; i += 3) SUBA[RN++] = i;
   for(int i = 2; i < AN; i += 3) SUBA[RN++] = i;
   A[AN + 1] = A[AN] = -1;
   radix_pass(A + 2, AN - 2, SUBA, RN, R);
   radix_pass(A + 1, AN - 1, R, RN, SUBA);
   radix_pass(A + 0, AN - 0, SUBA, RN, R);
   // Compute the relabel array if we need to recursively solve for the
   // non-multiples.
   int resfix, resmul, v;
   if(AN % 3 == 1) {
       resfix = 1; resmul = RN >> 1;
   } else {
       resfix = 2; resmul = RN + 1 >> 1;
   }
   for(int i = v = 0; i < RN; i++) {
       v += i && (A[R[i - 1] + 0]/SH != A[R[i] + 0]/SH ||
               A[R[i - 1] + 1]/SH != A[R[i] + 1]/SH ||
               A[R[i - 1] + 2]/SH != A[R[i] + 2]/SH);
       SUBA[R[i] / 3 + (R[i] % 3 == resfix) * resmul] = v;
   }
   // Recursively solve if needed to compute relative ranks in the final suffix
   // array of all non-multiples.
   if(v + 1 != RN) {
       suffix_array(SUBA, RN);
       SA[0] = AN;
       for(int i = 1; i <= RN; i++) {
           SA[i] = SA[i] < resmul ? 3 * SA[i] + (resfix==1?2:1) :
               3 * (SA[i] - resmul) + resfix;
       }
   } else {
       SA[0] = AN;
       memcpy(SA + 1, R, sizeof(int) * RN);
   }
   // Compute the relative ordering of the multiples.
   int NMN = RN;
   for(int i = RN = 0; i <= NMN; i++) {
       if(SA[i] % 3 == 1) {
           SUBA[RN++] = SA[i] - 1;
       }
   }
   radix_pass(A, AN, SUBA, RN, R);
   // Compute the reverse SA for what we know so far.
   for(int i = 0; i <= NMN; i++) {
       SUBA[SA[i]] = i;
   }
   // Merge the orderings.
   int ii = RN - 1;
   int jj = NMN;
   int pos;
   for(pos = AN; ii >= 0; pos--) {
       int i = R[ii];
       int j = SA[jj];
       int v = A[i] - A[j];
       if(!v) {
           if(j % 3 == 1) {
               v = SUBA[i + 1] - SUBA[j + 1];
           } else {
               v = A[i + 1] - A[j + 1];
               if(!v) v = SUBA[i + 2] - SUBA[j + 2];
           }
       }
       SA[pos] = v < 0 ? SA[jj--] : R[ii--];
   }
}
int n;
int s[MAXN + 1];
/* Copies the string in s into A and reduces the characters as needed. */
void prep_string() {
   int v = AN = 0;
   memset(cnt, 0, sizeof(cnt));
   for(int ss = 0; ss<n; ++ss, ++AN) cnt[s[ss]]++;
   for(int i = 0; i < AN; i++) cnt[s[i]]++;
   for(int i = 0; i < (256)*MAXN; i++) cnt[i] = cnt[i] ? v++ : -1;
   for(int i = 0; i < AN; i++) A[i] = cnt[s[i]];
}
/* Computes the reverse SA index.  REVSA[i] gives the index of the suffix
* starting a i in the SA array.  In other words, REVSA[i] gives the number of
* suffixes before the suffix starting at i.  This can be useful in itself but
* is also used for compute_lcp().
*/
int REVSA[256*MAXN + 1];
void compute_reverse_sa() {
   for(int i = 0; i <= AN; i++) {
       REVSA[SA[i]] = i;
   }
}
/* Computes the longest common prefix between adjacent suffixes.  LCP[i] gives
* the longest common suffix between the suffix starting at i and the next
* smallest suffix.  Runs in O(N) time.
*/
int LCP[MAXN + 1];
void compute_lcp() {
   int len = 0;
   for(int i = 0; i < AN; i++, len = max(0, len - 1)) {
       int s = REVSA[i];
       int j = SA[s - 1];
       for(; i + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);
       LCP[s] = len;
   }
}
LL sums[MAXN];
LL ps[MAXN];
LL sumn(LL n)
{
    return (n*(n+1))/2;
}
LL firsts[10*MAXN+10];
int main()
{

    string h;
    cin>>h;
    n = h.length();
    for(int i = 0;i<h.size();i++)
    {
       s[i]=h[i];
       s[i] = (SH)*(h[i]) + ++freq[h[i]];
       cout<<s[i]<<endl;
    }
    prep_string();
    suffix_array(A, AN);
    compute_reverse_sa();
    compute_lcp();
    for(int i=0; i<=n; i++)
       cout << LCP[i] << endl;
    printf("------\n");
    for(int i=0; i<=n; i++)
       cout << SA[i] << endl;
    printf("------\n");
    int lens=h.length(),index;
    LL sum=0ll;
    sums[0]=0;
    for(int i=1; i<=lens; i++)
    {
       LL p=((LL)(lens-SA[i])*(LL)(lens-SA[i]+1))/2ll
           - ((LL)LCP[i]*(LL)(LCP[i]+1))/2ll;
       ;

       //cout<<p<<endl;
       //if(p+sum>=k){k-=sum;index=i;break;}
       sum+=p;
       sums[i]=sum;
       ps[i]=p;
    }
    for(int i = 0;i<10*MAXN+10;i++)
    {
        firsts[i] =(i*(i+1))/2;
    }
    int q;
    cin>>q;
    LL g = 0;
    string ans;
    while(q--)
    {
        LL p,m;
        //cin>>p>>m;
        //LL k = (p*g)%m + 1;
        LL k;
        cin>>k;
        LL ss=0;
        index = lower_bound(sums+1,sums+lens+1,k)-(sums);
        k = k - sums[index] + ps[index];
        for(int i=LCP[index]+1; ; i++)
        {
           if((ss+i)>=k)
           {
               k-=ss;
               break;
           }
           ss+=i;
        }
        //cout<<ss<<endl;
        ans.push_back(char(s[(int)(SA[(int)index]+(int)k-(int)1 )]/SH ));
        g+=char(s[(int)(SA[(int)index]+(int)k-(int)1 )]/SH );
        cout <<char(s[(int)(SA[(int)index]+(int)k-(int)1 )]/SH )<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
