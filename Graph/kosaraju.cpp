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

vector<list<ll>> g;
vector<list<ll>> gt;
ll V = 0;

void dfs(ll node, vector<bool> &visited, stack<ll> &st){
    visited[node] = true;
    for(auto &nbr : g[node]){
        if(not visited[nbr]){
            dfs(nbr, visited, st);
        }
    }
    st.push(node);
}

void dfs(ll node, vector<bool> &visited, unordered_set<ll> &sc){
    visited[node] = true;
    sc.insert(node);
    for(auto &nbr: gt[node]){
        if(not visited[nbr]){
            dfs(nbr, visited, sc);
        }
    }
}

vector<unordered_set<ll>> kosaraju(){
    // Phase 1 
    // Build the connected stack through dfs
    stack<ll> st;
    vector<bool> visited(V, false);
    for(int i = 0 ; i < V ; i++){
        if(not visited[i]){
            dfs(i, visited, st);
        }
    }

    // Phase 2
    // from the transposed graph run the dfs from top of stack

    vector<unordered_set<ll>> result;
    visited.clear();
    visited.assign(V, false);
    while(not st.empty()){
        auto node = st.top();
        st.pop();
        if(not visited[node]){
            unordered_set<ll> sc;
            dfs(node, visited, sc);
            result.emplace_back(sc);
            sc.clear();
        }
    }
    return result;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    V = n;
    g.assign(n, list<ll>());
    gt.assign(n, list<ll>());
    while(m--){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    auto res = kosaraju();
    for(auto &sc : res){
        for(auto &el : sc){
            cout << el << " ";
        }
        cout << "\n";
    }
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