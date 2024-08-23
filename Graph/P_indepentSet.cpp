// Problem Link -> https://atcoder.jp/contests/dp/tasks/dp_p
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
vector<list<int>> graph;
vector<vi> dp;
enum{
    COLOR_WHITE,
    COLOR_BLACK
};

ll countWays(int node, int color, int parent){
    if(dp[node][color] != -1){
        return dp[node][color];
    }

    ll ways1 = 1;
    ll ans = 0;

    for(auto &nbr : graph[node]){
        if(nbr == parent) continue;
        ways1 = (ways1 * countWays(nbr, COLOR_WHITE, node)) % mod;
    }
    ans += ways1;
    if(color == COLOR_WHITE){
        ll ways2 = 1;
        for(auto &nbr : graph[node]){
            if(nbr == parent) continue;
            ways2 = (ways2 * countWays(nbr, COLOR_BLACK, node)) % mod;
        }
        ans += ways2;
    }
    return dp[node][color] = ans;
}

void solve() {
    ll N;
    cin >> N;
    graph.assign(N, list<int>());
    dp.assign(N, vi(2, -1));

    loop(i, 0 , N-1){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << countWays(0, 0, -1);
    
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