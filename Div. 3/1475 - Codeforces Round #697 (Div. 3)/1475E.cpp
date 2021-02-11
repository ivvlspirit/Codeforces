// If you're hacking me, at least subscribe to my channel at:
// https://www.youtube.com/user/ivanvlahov922

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

ll fac[2000];


/* Iterative Function to calculate (x^y)%p
in O(log y) */
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

    int TEST;
    cin >> TEST;

    fac[0] = 1;
    for (int i = 1; i <= 2000; i++)
        fac[i] = (fac[i - 1] * i) % MOD;

    for(; TEST; TEST--){
        // Don't forget to clear global variables if recursive
        int n, k;
        cin >> n >> k;

        map<int, int> occ;
        int a[n];

        for(int i=0; i<n; i++){
            int f;
            cin >> f;
            a[i] = f;

            if(occ.count(f) == 0){
                occ[f] = 1;
            }else{
                occ[f]++;
            }
        }

        sort(a, a+n);

        multiset<int> best;

        for(int i=0; i<k; i++){
            best.insert(a[n-1-i]);
        }

        ll res = 0;

        ll resocc = occ[*best.begin()];
        ll bestocc = best.count(*best.begin());

        // res = (resocc*(resocc-1))/2;
        // cout << resocc << " " << bestocc << endl;
        res = nCrModPFermat(resocc, bestocc, MOD);
        cout << res;
        
        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}