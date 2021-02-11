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
        ll n, m;
        cin >> n >> m;

        ll a[n], b[n];
        ll memsum = 0;

        for(int i=0; i<n; i++){
            cin >> a[i];
            memsum += a[i];
        }

        for(int i=0; i<n; i++){
            cin >> b[i];
        }

        if(memsum < m){
            cout << "-1";
        }else{
            vector<ll> jed, dva;

            for(int i=0; i<n; i++){
                if(b[i] == 1){
                    jed.push_back(a[i]);
                }else{
                    dva.push_back(a[i]);
                }
            }

            sort(jed.begin(), jed.end());
            sort(dva.begin(), dva.end());
            reverse(jed.begin(), jed.end());
            reverse(dva.begin(), dva.end());

            // vector<int> dvap, jedp;
            ll dvap[dva.size()+1], jedp[jed.size()+1];

            jedp[0] = 0;
            dvap[0] = 0;

            for(int i=0; i<jed.size(); i++){
                jedp[i+1] = jedp[i] + jed[i];
            }

            for(int i=0; i<dva.size(); i++){
                dvap[i+1] = dvap[i] + dva[i];
            }

            int res = n*2+1;

            for(int i=0; i<dva.size()+1; i++){
                int jp = lower_bound(jedp, jedp+jed.size()+1, m-dvap[i])-jedp;
                if(jp != jed.size()+1){
                    res = min(res, 2*i+jp);
                }
            }

            cout << res;


        }
        
        
        
        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}