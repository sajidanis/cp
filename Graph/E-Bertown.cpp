// Problem Link -> https://codeforces.com/contest/118/problem/E
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
int disc[100005];
int low[100005];
int dtime = 1;
int bridges = 0;

void dfs(int cur, int par){
    disc[cur] = dtime;
    low[cur] = dtime;
    dtime++;

    int nc = 0;

    for(auto &child : graph[cur]){
        if(disc[child] == 0){
            dfs(child, cur);
            nc++;
            low[cur] = min(low[cur], low[child]);
            if(low[child] > disc[cur]){
                bridges++;
            } 
        }else {
            // back edges
            if(child != par)
                low[cur] = min(low[cur], disc[child]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    graph.assign(n+1, list<int>());

    while(m--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    if(bridges > 0){
        cout << 0;
        return;
    }

    int k = 0;

    for(int i = 1 ; i <= n ; i++){
        k = 0;
        for(auto &child : graph[i]){
            if(child < i) continue;
            if(k % 2){
                // odd
                // Make the edge inward
                cout << child << " " << i << "\n";
            } else {
                cout << i << " " << child << "\n";
            }
            k++;
        }
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