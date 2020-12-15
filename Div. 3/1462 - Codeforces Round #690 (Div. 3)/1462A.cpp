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

        for(int i=0; i<n; i++){
            if(i%2==0){
                cout << a[i/2];
            }else{
                cout << a[n-i/2-1];
            }

            cout << " ";
        }


        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}