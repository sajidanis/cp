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

vi dp;

ll ways(ll sum, ll n, vi &coins){
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(dp[sum] != -1) return dp[sum];
    ll ans = 0;

    loop(i, 0, n){
        if(sum - coins[i] >= 0){
            ans = (ans + ways(sum - coins[i], n, coins)) % mod;
        }
    }
    return dp[sum] = ans;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    vi coins(n);
    loop(i, 0, n){
        cin >> coins[i];
    }
    dp.assign(x+1, -1);
    cout << ways(x, n, coins);
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