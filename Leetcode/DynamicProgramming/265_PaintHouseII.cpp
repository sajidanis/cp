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

ll f(vector<vi> &cost){
    ll n = cost.size();
    ll k = cost[0].size();

    vector<vi> dp(n, vi(k, inf));
    loop(i, 0, k){
        dp[0][i] = cost[0][i];
    }

    loop(i, 1, n){
        loop(j, 0, k){
            loop(m, 0, k){
                if(m == j) continue;
                dp[i][j] = min(dp[i][j], cost[i][j] + dp[i-1][m]);
            }
        }
    }

    ll result = inf;

    loop(j, 0, k){
        result = min(dp[n-1][j], result);
    }

    return result;

}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<vi> cost(n, vi(k, 0));
    loop(i, 0, n){
        loop(j, 0, k){
            cin >> cost[i][j];
        }
    }

    cout << f(cost);
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