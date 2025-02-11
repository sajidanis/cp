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

ll holi(ll u, vector<list<pair<int, int>>> &graph, vector<bool> &vis, vi &count, int n, ll &ans){
    vis[u] = true;
    count[u] = 1;
    for(auto &nbr : graph[u]){
        if(not vis[nbr.second]){
            count[u] += holi(nbr.second, graph, vis, count, n, ans);
            ans += 2 * min(count[u], n-count[u]) * nbr.first;
        }
    }
    return count[u];
}

ll dfs(int n, vector<list<pair<int, int>>> &graph){
    vector<bool> vis(n, false);
    vi count(n, 0);

    ll ans = 0;
    holi(0, graph, vis, count, n, ans);
    return ans;
}

void solve() {
    ll N;
    cin >> N;
    vector<list<pair<int, int>>> graph(N, list<pair<int, int>>());
    loop(i, 0, N-1){
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    cout << dfs(N, graph);
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