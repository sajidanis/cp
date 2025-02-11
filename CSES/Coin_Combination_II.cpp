// Problem Link -> https://cses.fi/problemset/task/1636
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

vs coinCombinations(ll amount, vi &coins){
    if(amount == 0){
        return {""};
    }
    vs res;
    for(ll j = 0 ; j < coins.size(); j++ ){
        string temp = "";
        if(amount - coins[j] < 0) continue;
        auto prev = coinCombinations(amount - coins[j], coins);
        for(auto &el : prev){
            res.push_back(el + to_string(coins[j]) + " ");
        }
    }
    return res;
}

ll coinCombinationsII(ll amount, vi &coins){
    vi dp(amount + 1, 0);

    dp[0] = 1;

    for(ll j = 0 ; j < coins.size() ; j++){
        for(ll i = 1 ; i <= amount ; i++){
            if(i - coins[j] < 0) continue;
            dp[i] = (dp[i] + dp[i-coins[j]]) % mod;
        }
    }

    return dp[amount];
}

void solve() {
    ll n, x;
    cin >> n >> x;

    vi coins(n);

    loop(i, 0, n){
        cin >> coins[i];
    }

    auto res = coinCombinationsII(x, coins);
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