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

    int t;
    cin >> t;

    for(; t; t--){
        int n;
        cin >> n;

        int a[n];

        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        sort(a, a+n);

        ll res = 0;

        map<int, int> lastOcc;


        for(int i=0; i<n-2; i++){
            ll ind;
            if(lastOcc.count(a[i])){
                ind = lastOcc[a[i]];
            }else{
                ind = lower_bound(a, a+n, a[i]+3) - a;
                lastOcc[a[i]] = ind;
            }

            ll num = ind - i - 1;

            res += (num)*(num-1)/2;
        }

        cout << res;

        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}