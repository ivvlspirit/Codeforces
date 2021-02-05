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
        int x, y;
        cin >> x >> y;

        char a, b;
        if(x>0) a = 'R';
        else a = 'L';

        if(y>0) b = 'U';
        else b = 'D';

        int sx = 0, sy = 0;
        string s;
        cin >> s;

        for(int i=0; i<s.length(); i++){
            if(s[i] == a) sx++;
            if(s[i] == b) sy++;
        }

        if(sx >= abs(x) && sy>=abs(y)){
            cout << "YES";
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