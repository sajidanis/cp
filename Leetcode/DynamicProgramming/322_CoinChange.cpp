// Problem Link -> https://leetcode.com/problems/coin-change/description/
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
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
}

ll minCoinTD(vi &coins, ll value, vi &dp){
    if(value < 0){
        return INT32_MAX;
    }
    if(value == 0){
        return 0;
    }

    if(dp[value] != 0){
        return dp[value];
    }

    ll currVal = INT_MAX;

    for(int j = 0 ; j < coins.size(); j++){
        if(value - coins[j] < 0) continue;
        currVal = min(currVal, minCoinTD(coins, value-coins[j], dp));
    }
    dp[value] = ((currVal == INT_MAX) ? -1 : (1 + currVal));
    return dp[value];
}

ll minCoinBU(ll value, vi &coins){
    vi dp(value + 1);
    dp[0] = 0;

    for(ll i = 1 ; i <= value ; i++){
        ll currVal = INT_MAX;
        for(int j = 0 ; j < coins.size(); j++){
            if(i - coins[j] < 0) continue;
            currVal = min(currVal, dp[i-coins[j]]);
        }
        dp[i] = (currVal == INT_MAX) ? INT_MAX : (1 + currVal);
    }

    return dp[value];
}

ll minCoin(ll amount, ll n, vi &coins){
    if(amount < 0 ){
        return inf;
    }

    if(amount == 0){
        return 0;
    }

    ll res = inf;
    for(ll i = 0; i < n ; i++){
        res = min(res, 1 + minCoin(amount - coins[i], n, coins));
    }
    return res;
}

void solve() {
    ll n;
    vi coins(n);
    cin >> n;
    ll amount;

    loop(i, 0, n){
        cin >> coins[i];
    }

    cin >> amount;

    auto res = minCoin(amount, n, coins);

    cout << res;
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