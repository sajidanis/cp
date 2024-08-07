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

vi wt;
vi c;

ll dp[105][100005];

ll knapsack(ll i, ll w, ll n){
    if(i == n){
        return 0;
    }
    if(w <= 0) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    // pick
    ll res = 0;
    ll f1 = 0;
    if(wt[i] <= w){
        f1 = c[i] + knapsack(i+1, w-wt[i], n);
    }
    ll f2 = knapsack(i+1, w, n);
    res = max(f1, f2);
    return dp[i][w] = res;
}

ll knapsackBU(ll W, ll n){
    vector<vi> dp(n+1, vi(W+1, 0));
    loop(i, 1, n+1){
        loop(j, 1, W+1){
            dp[i][j] = dp[i-1][j];
            if(wt[i] <= j){
                dp[i][j] = max(dp[i][j], c[i] + dp[i-1][j-wt[i]]);
            }
        }
    }
    return dp[n][W];
}

ll knapsacBU_better(ll W, ll n){
    vi dp1(W+1, 0);
    vi dp2(W+1, 0);

    loop(i, 1, n+1){
        loop(j, 1, W+1){
            dp2[j] = dp1[j];
            if(wt[i] <= j){
                dp2[j] = max(dp1[j], c[i] + dp1[j-wt[i]]);
            }
        }
        dp2.swap(dp1);
        dp2.clear();
    }
    return dp1[W];
}

void solve() {
    memset(dp, -1, sizeof dp);
    ll n, W;
    cin >> n >> W;
    wt.push_back(0);
    c.push_back(0);
    loop(i, 0, n){
        ll w, cost;
        cin >> w >> cost;
        wt.push_back(w);
        c.push_back(cost);
    }

    // cout << knapsack(0, W, n);
    cout << knapsackBU(W, n);
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