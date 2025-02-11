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

bool has_path(vector<list<int>> &g , int start, int end, vector<bool> &vis){
    if(start == end){
        return true;
    }
    vis[start] = true;
    for(auto neighbour : g[start]){
        if(not vis[neighbour]){
            bool result = has_path(g, neighbour, end, vis);
            if(result) return true;
        }
    }
    return false;
}

// ll calcAllPaths(vector<list<int>> &g, int start, int end, vector<bool> &vis){
//     if(start == end){
//         return 1;
//     }
//     ll res = 0;
//     vis[start] = true;
//     for(auto nbr : g[start]){
//         if(not vis[nbr]){
//             auto t1 = calcAllPaths(g, nbr, end, vis);
//             res += t1;
//         }
//     }
//     vis[start] = false;
//     return res;
// }


vector<vi> calcAllPaths(vector<list<int>> &g, int start, int end, vector<bool> &vis){
    if(start == end){      
        return {{start}};
    }
    vector<vi> res;
    vis[start] = true;
    for(auto nbr : g[start]){
        if(not vis[nbr]){
            auto t1 = calcAllPaths(g, nbr, end, vis);
            for(auto &el : t1){
                el.insert(el.begin(), {start});
                res.push_back(el);
            }
        } 
    }
    vis[start] = false;
    return res;
}


void solve() {
    vector<list<int>> g; // adjacency list
    int v, e;
    cin >> v;
    g.resize(v, list<int>());

    cin >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        // if undirected
        g[v].push_back(u);
    }

    vector<bool> vis(v, false);
    auto res = calcAllPaths(g, 0, 5, vis);
    for(auto &el : res){
        for(auto &v : el){
            cout << v << " ";
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