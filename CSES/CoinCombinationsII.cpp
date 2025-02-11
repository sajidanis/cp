// Problem Link -> https://cses.fi/problemset/task/1635
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

void solve() {
    ll n, x;
    cin >> n >> x;
    vi coins(n);
    loop(i, 0, n){
        cin >> coins[i];
    }

    vector<vi> dp(2, vi(x+1, 0));

    dp[0][0] = 1;

    loop(i, 1, n+1){
        loop(j, 0, x+1){
            dp[i&1][j] = dp[i & 1 ^ 1][j];
            if(j - coins[i-1] >= 0){
                dp[i&1][j] = (dp[i&1][j] + dp[i&1][j-coins[i-1]]) % mod;
            }
        }
    }
    cout << dp[n&1][x];
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