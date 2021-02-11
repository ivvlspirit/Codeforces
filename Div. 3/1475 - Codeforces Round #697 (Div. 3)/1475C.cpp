// If you're hacking me, at least subscribe to my channel at:
// https://www.youtube.com/user/ivanvlahov922

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

int main(){

    #ifdef DEBUG
        freopen("..\\input.txt", "r", stdin);
        clock_t tStart = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TEST;
    cin >> TEST;

    for(; TEST; TEST--){
        // Don't forget to clear global variables if recursive
        ll a, b, k;
        cin >> a >> b >> k;

        vector<ll> m(k), f(k);


        vector<ll> occm(a+1, 0), occf(b+1, 0);

        for(int i=0; i<k; i++){
            cin >> m[i];
            occm[m[i]]++;
        }

        for(int i=0; i<k; i++){
            cin >> f[i];
            occf[f[i]]++;
        }

        ll res = (k*(k-1))/2;

        for(int i=1; i<=a; i++){
            res -= (occm[i]*(occm[i]-1))/2;
        }

        for(int i=1; i<=b; i++){
            res -= (occf[i]*(occf[i]-1))/2;
        }
        
        cout << res;




        
        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}