// Problem Link -> https://vjudge.net/problem/CodeChef-DAGXOR
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

vector<list<ll>> graph;
ll V = 0;
ll ans = 0;
int d[4] = {0, 1, 2, 3};
ll dp[100005][4][4];

void addLeaftoNode(ll node, ll parent){
    bool leaf = true;
    for(auto &nbr : graph[node]){
        if(nbr == parent) continue;
        leaf = false;
        addLeaftoNode(nbr, node);
    }
    if(leaf){
        graph[node].push_back(V-1);
        graph[V-1].push_back(node);
    }
}

ll countXorSum(ll node, ll par, ll val, ll cur_sum){
    if(node == V-1){
        return (val ^ cur_sum) == 0;
    }
    if(dp[node][val][cur_sum] != -1){
        return dp[node][val][cur_sum];
    }
    auto new_sum = val ^ cur_sum;
    ll result = 0;
    for(auto &nbr : graph[node]){
        ll res = 1;
        if(nbr == par) continue;
        for(int i = 0 ; i < 4 ; i++){
            res = (res * countXorSum(nbr, node, d[i], new_sum)) % mod;
        }
        result = (res + result) %mod;
    }
    return dp[node][val][cur_sum] = result;
}

void solve() {
    ll N;
    cin >> N;
    V = N;
    graph.assign(N, list<ll>());
    memset(dp, -1, sizeof(ll)*100005*4*4);
    
    loop(i, 0, N-2){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    addLeaftoNode(0, -1);
    ll res = 0;
    for(int i = 0 ; i < 4 ; i++){
        res = (res + countXorSum(0, -1, d[i], 0)) % mod;
    }
    cout << res;
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