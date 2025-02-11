// Problem Link -> https://codeforces.com/problemset/problem/1118/F1
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


ll red = 0;
ll blue = 0;
ll result = 0;
pii dfs(vector<list<ll>> &g, vi &color, ll node, ll parent = -1){
    pii ans(0, 0);
    for(auto &nbr : g[node]){
        if(nbr != parent){
            pii p = dfs(g, color, nbr, node);
            result += (p.first == blue and p.second == 0);
            result += (p.first == 0 and p.second == red);
            ans.first += p.first;
            ans.second += p.second;
        }
    }
    if(color[node] == 1) ans.second++;
    else if(color[node] == 2) ans.first++;
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    vi color(n+1, 0);
    loop(i, 0, n){
        cin >> color[i+1];
        if(color[i+1] == 2) red++;
        if(color[i+1] == 1) blue++;
    }
    
    vector<list<ll>> graph(n+1, list<ll>());

    loop(i, 0, n-1){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(graph, color, 1);

    cout << result;
    
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