#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;
unsigned ll fac[200001];

// ll choose(int n, int k){
//     return factorials[n] / (factorials[n-k]*factorials[k]);
// }

unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0) 
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    fac[0] = 1;
    fac[1] = 1;

    for(int i=2; i<200001; i++){
        fac[i] = (fac[i-1]*i)%MOD;
    }

    for(; t; t--){
        int n, m, k;
        cin >> n >> m >> k;

        int a[n];

        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        sort(a, a+n);

        ll res = 0;

        map<int, int> lastOcc;

        if(m==1){
            res = n;
        }else{
            for(int i=0; i<n-m+1; i++){
                ll ind;
                if(lastOcc.count(a[i])){
                    ind = lastOcc[a[i]];
                }else{
                    ind = lower_bound(a, a+n, a[i]+k+1) - a;
                    lastOcc[a[i]] = ind;
                }

                unsigned ll num = ind - i - 1;

                res += nCrModPFermat(num, m-1, MOD);
                res = res%MOD;
            }
        }

        

        cout << res;

        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}