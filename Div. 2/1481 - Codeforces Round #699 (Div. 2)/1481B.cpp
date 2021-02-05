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
        int n, k;
        cin >> n >> k;

        int h[n];

        for(int i=0; i<n; i++){
            cin >> h[i];
        }

        bool cond = true;
        int res = 0;

        for(int i=0; i<k; i++){
            int p = 0;
            while(p<n-1 && h[p]>=h[p+1]){
                p++;
            }

            if(p == n-1){
                res = -1;
                break;
            }else{
                res = p;
                h[p]++;
            }
        }

        if(res!=-1){
            cout << res+1;
        }else{
            cout << res;
        }
        
        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}