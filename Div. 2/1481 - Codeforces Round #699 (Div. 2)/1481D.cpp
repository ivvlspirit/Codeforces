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

        string s[n];
        for(int i=0; i<n; i++){
            cin >> s[i];
        }

        int p=1, d=2;

        bool same = false;

        for(int i=0; i<n && !same; i++){
            for(int j=i+1; j<n && !same; j++){
                if(s[i][j] == s[j][i]){
                    p = i+1;
                    d = j+1;
                    same = true;
                }
            }
        }
        
        if(same || m%2==1){
            cout << "YES\n";

            for(int i=0; i<=m; i++){
                if(i%2==0){
                    cout << p;
                }else{
                    cout << d;
                }

                cout << " ";
            }
        }else{
            bool res = false;

            int vals[4];

            for(int i=0; i<n && !res; i++){
                for(int j=i+1; j<n && !res; j++){
                    for(int k=0; k<n && !res; k++){
                        if(k==i || k==j) continue;

                        if(s[i][j] == s[j][k]){
                            res = true;

                            vals[0] = i+1;
                            vals[1] = j+1;
                            vals[2] = k+1;
                            vals[3] = j+1;
                        }else if(s[j][i] == s[i][k]){
                            res = true;

                            vals[0] = j+1;
                            vals[1] = i+1;
                            vals[2] = k+1;
                            vals[3] = i+1;
                        }

                    }
                }
            }

            if(res){
                cout << "YES\n";

                if((m/2)%2==0){
                    // cout << "aaa";
                    for(int i=0; i<m+1; i++){
                        cout << vals[(i+1)%4] << " ";
                    }
                }else{
                    for(int i=0; i<m+1; i++){
                        cout << vals[i%4] << " ";
                    }
                }
            }else{
                cout << "NO";
            }
        }
        
        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}