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

        int sum = 0;

        for(int i=0; i<n; i++){
            cin >> a[i];
            sum+=a[i];
        }

        int ps[n];
        ps[0] = a[0];

        for(int i=1; i<n; i++){
            ps[i] = ps[i-1]+a[i];
        }

        for(int i=n; i>0; i--){
            if(sum % i != 0) continue;

            int cnt = 0;

            for(int j=0; j<n; j++){
                if(ps[j] % (sum/i) == 0){
                    cnt++;
                }
            }

            if(cnt == i){
                cout << n-i;
                i=-1;
            }
        }


        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}