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

vector<list<int>> graph;
int cntr = 1;
int disc[100005];
int low[100005];
int dtime;

void dfs(int curr, int parent){
    disc[curr] = dtime;
    low[curr] = dtime;
    dtime++;
    int nc = 0;
    for(auto child : graph[curr]){
        if(disc[child] == 0){
            dfs(child, curr);
            nc++;
            low[curr] = min(low[curr], low[child]);
            if(parent != 0 and low[child] >= disc[curr]){
                cout << "Articulation Point found: " << curr << "\n";
            }
            if(low[child] > disc[curr]){
                cout << "Bridges Found: " << curr << " - " << child << "\n";
            }
        } else {
            if(child != parent){
                // backedge
                low[curr] = min(low[curr], disc[child]);
            }
        }
    }
    if(parent == 0 and nc >= 2){
        cout << "Articulation Point found: " << curr << "\n";
    }
}

void dfs(int start, vi &tin, vi &tout, vector<bool> &visited){
    visited[start] = true;
    tin[start] = cntr++;

    for(auto &nbr : graph[start]){
        if(not visited[nbr]){
            dfs(nbr, tin, tout, visited);
        }
    }
    tout[start] = cntr++;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    graph.assign(n, list<int>());

    vi tin(n);
    vi tout(n);
    vector<bool> visited(n, false);

    while(m--){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, 0);

    // dfs(0, tin, tout, visited);

    // for(auto &el : tin){
    //     cout << el << " ";
    // }

    // cout << "\n";

    // for(auto &el : tout){
    //     cout << el << " ";
    // }

    // cout << "\n";

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