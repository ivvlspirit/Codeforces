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
        int n, m;
        cin >> n >> m;

        int a[n], b[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        vector<vector<int>> need(n+1), notneed(n+1);

        for(int i=0; i<n; i++){
            cin >> b[i];

            if(a[i] == b[i]){
                notneed[b[i]].push_back(i);
            }else{
                need[b[i]].push_back(i);
            }
        }

        int c[m];
        vector<int> fix;

        vector<int> vres(m);

        for(int i=0; i<m; i++){
            cin >> c[i];

            if(need[c[i]].size() > 0){
                for(auto it : fix){
                    vres[it] = need[c[i]].back();
                }
                fix.clear();

                vres[i] = need[c[i]].back();
                need[c[i]].pop_back();
                notneed[c[i]].push_back(vres[i]);
            }else{
                if(notneed[c[i]].size() > 0){
                    for(auto it : fix){
                        vres[it] = notneed[c[i]].back();
                    }
                    fix.clear();

                    vres[i] = notneed[c[i]].back();
                }else{
                    fix.push_back(i);
                }
            }
        }

        bool res = true;
        for(int i=1; i<=n; i++){
            if(need[i].size() > 0) res = false;
        }

        if(fix.size() > 0) res = false;

        if(res){
            cout << "YES\n";
            for(auto it : vres){
                cout << it+1 << " ";
            }
        }else{
            cout << "NO";
        }
        



        
        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}