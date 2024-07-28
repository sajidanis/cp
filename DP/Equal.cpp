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
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
}
ll minCoinsGreedy(ll value){
    ll res = 0;
    res += value / 5;

    value = value % 5;

    res += value / 2;
    value %= 2;

    res += value;

    return res;
}

vi coins = {1, 2, 5};
vi dp(1005, -1);
ll minCoins(ll value, vi &coins, vi &dp){
    if(value == 0){
        return 0;
    }

    if(dp[value] != -1){
        return dp[value];
    }

    ll res = inf;

    for(ll i = 0 ; i < coins.size() ; i++){
        if(value - coins[i] < 0) continue;
        res = min(res, minCoinsGreedy(value-coins[i]));
    }

    dp[value] = res == inf ? inf : res + 1;
    return dp[value];
}

void solve() {
    ll n;
    cin >> n;
    vi arr(n);
    loop(i, 0, n){
        cin >> arr[i];
    }

    ll min_el = *min_element(arr.begin(), arr.end());
    ll res = inf;
    loop(i, min_el-4, min_el+1){
        ll temp_res = 0;
        loop(j, 0, n){
            temp_res += minCoins(arr[j] - i, coins, dp);
        }
        res = min(res, temp_res);
    }
    cout << res;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    cin >> t;
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