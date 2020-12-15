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

        vector<pair<int, int>> lines;


        for(int i=0; i<n; i++){
            int l, r;
            cin >> l >> r;

            lines.push_back({l, r});
        }

        sort(lines.begin(), lines.end());

        vector<int> diff(2*n, 0);
        // diff[0] = 1;

        for(int i=0; i<lines.size(); i++){
            pair<int, int> temp1 = {lines[i].first, 0}, temp2 = {lines[i].second, 1e9};

            int ub = upper_bound(lines.begin(), lines.end(), temp2) - lines.begin();
            // int lb = lower_bound(lines.begin(), lines.end(), temp1) - lines.begin();
            int lb = i;

            int intersection = ub - lb;

            // cout << i << " " << ub << " " << lb << endl;
            diff[i] += intersection;
            diff[i+1] -= intersection;

            diff[i+1]++;
            diff[i+intersection]--;
        
        }

        int mx = 0;
        int curr;

        // for(int i=0; i<n; i++){
        //     cout << diff[i] << " ";   
        // }
        // cout << endl;

        for(int i=0; i<diff.size(); i++){
            if(i==0){
                mx = diff[i];
                curr = diff[i];
            }else{
                curr+=diff[i];
                mx = max(mx, curr);
            }
        }

        cout << n-mx;




        cout << "\n";
    }

    #ifdef DEBUG
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif

    return 0;
}