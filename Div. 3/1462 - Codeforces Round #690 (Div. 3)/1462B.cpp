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

        string s;
        cin >> s;

        if(s.substr(0, 4) == "2020" || (s.substr(0, 3) == "202" && s[n-1] == '0') || (s.substr(0, 2) == "20" && s.substr(n-2) == "20") || (s[0] == '2' && s.substr(n-3) == "020") || (s.substr(n-4) == "2020")){
            cout << "YES";
        } else{
            cout << "NO";
        }


        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}