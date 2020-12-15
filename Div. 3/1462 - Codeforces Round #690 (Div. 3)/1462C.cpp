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
        int x;
        cin >> x;

        vector<int> num;

        for(int i=9; i>0; i--){
            if(x>=i){
                num.push_back(i);
                x-=i;
            }
        }

        if(x>0){
            cout << "-1";
        }else{
            for(int i=num.size()-1; i>=0; i--){
                cout << num[i];
            }
        }

    

        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}