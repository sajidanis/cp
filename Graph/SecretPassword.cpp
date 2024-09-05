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

vector<unordered_set<ll>> g;

void dfs(ll node, vector<bool> &vis){
    vis[node] = true;
    for(auto &nbr : g[node]){
        if(not vis[nbr]){
            dfs(nbr, vis);
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    g.assign(26, unordered_set<ll>());
    vector<bool> nodes(26, false);
    
    loop(i, 0, n){
        string inp;
        cin >> inp;
        nodes[inp[0] - 'a'] = true;
        loop(j, 1, inp.size()){
            g[inp[j-1] - 'a'].insert(inp[j] - 'a');
            g[inp[j] - 'a'].insert(inp[j-1] - 'a');
            nodes[inp[j] - 'a'] = true;
        }
    }
    vector<bool> vis(26, false);
    ll res = 0;
    loop(i, 0, 26){
        if(nodes[i] and not vis[i]){
            dfs(i, vis);
            res++;
        }
    }
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