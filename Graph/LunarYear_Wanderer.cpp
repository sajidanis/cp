// Problem Link -> https://codeforces.com/problemset/problem/1106/d?locale=en
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

vector<set<ll>> graph;

void dfs(ll node, vector<bool> &vis, vi &res){
    vis[node] = true;
    res.push_back(node);
    for(auto &nbr : graph[node]){
        if(not vis[nbr]){
            dfs(nbr, vis, res);
        }
    }
}

void bfs(ll node, vector<bool> &vis){
    set<int> q;
    vis[node] = true;
    q.insert(node);

    while(!q.empty()){
        auto u = *q.begin();
        cout << u+1 << " ";
        q.erase(u);

        for(auto &nbr: graph[u]){
            if(not vis[nbr]){
                vis[nbr] = true;
                q.insert(nbr);
            }
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    graph.assign(n, set<ll>());
    while(m--){
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(u == v) continue;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    vector<bool> vis(n, false);
    vi res;
    bfs(0, vis);

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