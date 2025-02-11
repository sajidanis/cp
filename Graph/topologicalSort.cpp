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


// Kahns algorithm
void topologicalSort(ll v){
    vector<bool> visited(v, false);
    vi indegree(v, 0);
    for(auto edgeList : g){
        for(auto v : edgeList){
            indegree[v]++; 
        }
    }
    queue<ll> q;
    for(int i = 0 ; i < v ; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        auto node = q.front();
        q.pop();
        cout << node << " ";
        visited[node] = true;
        for(auto nbr : g[node]){
            if(visited[nbr]) continue;
            indegree[nbr]--;
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }
}


void solve() {
    ll n, m;
    cin >> n >> m;
    g.assign(n, list<ll>());

    while(m--){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    topologicalSort(n);
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