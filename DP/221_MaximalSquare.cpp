// Problem Link ->
/* Md Sajid Anis */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb              emplace_back
#define vi              vector<ll>
#define vs              vector<string>
#define pii             pair<ll,ll>
#define ump             unordered_map
#define mp              map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff              first
#define ss              second
#define loop(var, start, end) for(ll var = start; var < end; var++)
#define loop_rev(var, start, end) for(ll var = start; var > end; var--)

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input", "r", stdin);
    freopen("../output", "w", stdout);
#endif
}

int maximalSquare(vector<vector<char>>& matrix) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int m = matrix.size();
    int n = matrix[0].size();

    int dp[m][n];

    memset(dp, 0, sizeof(dp));

    for(int i = 0 ; i < n ; i++){
        dp[0][i] = matrix[0][i];
    }

    for(int i = 1; i < m ; i++){
        dp[i][0] = matrix[i][0];
    }
    int ans = 1;
    for(int i = 1; i < m ; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0) continue;
            int k = 1;
            for(; k <= dp[i-1][j-1] ; k++){
                if(matrix[i-k][j] != 1 or matrix[i][j-k] != 1){
                    break;
                }
            }
            dp[i][j] = k;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans * ans;
}

void solve() {
    int m, n;
    cin >> m >> n;

}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    //cin >> t;
    while (t--) {
         solve();
         cout << "\n";
     }
#ifndef ONLINE_JUDGE
     clock_t end = clock();
     cerr << "\n[Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms]\n";
#endif
     return 0;
}