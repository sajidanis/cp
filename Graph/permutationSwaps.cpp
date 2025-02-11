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

vector<list<ll>> graph;
vi p;
vi q;

bool isSame(vi &t, vi &u){
    loop(i, 0, t.size()){
        if(t[i] != u[i]){
            return false;
        }
    }
    return true;
}

void dfs(ll src, vector<bool> &vis, vi &a, vi &b ){
    if(vis[src]){
        return;
    }

    vis[src] = true;
    p.push_back(a[src-1]);
    q.push_back(b[src-1]);
    for(auto &nbr : graph[src]){
        if(not vis[nbr]){
            dfs(nbr, vis, a, b);
        }
    }
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vi A(N), B(N);
    loop(i, 0, N){
        cin >> A[i];
    }
    loop(i, 0, N){
        cin >> B[i];
    }

    vector<bool> vis(N+1, false);

    graph.assign(N+1, list<ll>());

    loop(i, 0, M){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    loop(i, 1, N+1){
        if(not vis[i]){
            p.clear();
            q.clear();
            dfs(i, vis, A, B);
            sort(p.begin(), p.end());
            sort(q.begin(), q.end());
            if(not isSame(p, q)){
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
    return;

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