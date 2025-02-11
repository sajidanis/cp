// Problem Link -> https://cses.fi/problemset/task/1746
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


ll dp[100005][102];

ll getWays(ll idx, ll prev, ll m, vi &arr){
    if(idx >= arr.size()){
        return 1;
    }

    if(dp[idx][prev] != -1){
        return dp[idx][prev];
    }

    ll ans = 0;

    if(arr[idx] != 0){
        if(prev != 0 and abs(arr[idx] - prev) > 1) return 0;
        ans = getWays(idx+1, arr[idx], m, arr);
    } else {
        if(prev == 0){
            for(int i = 1; i <= m; i++){
                ans += getWays(idx+1, i, m, arr);
            }
        } else {
            for(int i = max(1LL, prev-1); i <= min(m, prev+1); i++){
                ans += getWays(idx+1, i, m, arr);
            }
        }
    }
    return dp[idx][prev] = ans % mod;
}


void solve() {
    ll n, m;
    cin >> n >> m;
    vi arr(n);
    loop(i, 0, n) cin >> arr[i];

    memset(dp, 0, sizeof dp);

    if(arr[0] != 0) dp[0][arr[0]] = 1;
    else {
        loop(i, 1, m+1){
            dp[0][i] = 1;
        }
    }
    
    loop(i, 1, n+1){
        if(arr[i] != 0){
            dp[i][arr[i]] += dp[i-1][arr[i] - 1];
            dp[i][arr[i]] += dp[i-1][arr[i]];
            dp[i][arr[i]] += dp[i-1][arr[i] + 1];
            dp[i][arr[i]] = dp[i][arr[i]] % mod;
            continue;
        }
        loop(j, 1, m+1){
            if(j - 1 > 0) dp[i][j] += dp[i-1][j - 1];
            dp[i][j] += dp[i-1][j];
            if(j+1 <= m) dp[i][j] += dp[i-1][j + 1];

            dp[i][j] = dp[i][j] % mod;
        }
    }

    ll ans = 0;
    loop(j, 1, m+1){
        ans += dp[n-1][j];
        ans = ans % mod;
    }

    cout << ans;

    // cout << getWays(0, 0, m, arr);
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