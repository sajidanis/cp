// Problem Link -> https://atcoder.jp/contests/dp/tasks/dp_g
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

void longest_distance(int src, int dest, vector<list<int>> &graph, vi &distance){
    if(src == dest){
        return;
    }

    for(auto &nbr: graph[src]){
        distance[nbr] = max(distance[nbr], distance[src] + 1);
        longest_distance(nbr, dest, graph, distance);
    }
}

ll longestPath(ll u, vector<list<int>> &graph, vi &dp){
    if(dp[u] != -1) return dp[u];
    ll leaf = 1;
    ll maxValue = INT_MIN;
    for(auto child : graph[u]){
        leaf = 0;
        maxValue = max(maxValue, longestPath(child, graph, dp));
    }
    return dp[u] = (leaf) ? 0 : 1+maxValue;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<list<int>> graph(N+1, list<int>());
    vi nodes(N+1, -1);
    vi distances(N+1, 0);
    loop(i, 0, M){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        nodes[v] = 0;
    }

    vi srcs, dest;
    for(int i = 1 ; i < N+1 ; i++){
        if(nodes[i] == -1){
            srcs.push_back(i);
        }
    }

    for(int i = 1 ; i < N+1 ; i++){
        if(graph[i].size() == 0){
            dest.push_back(i);
        }
    }

    for(auto &s : srcs){
        for(auto &d : dest){
            longest_distance(s, d, graph, distances);
        }
    }

    auto res = *max_element(distances.begin(), distances.end());
    
    vi dp(N+1, -1);
    ll result = INT_MIN;
    for(auto &src : srcs){
        result = max(result, longestPath(src, graph, dp));
    }

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