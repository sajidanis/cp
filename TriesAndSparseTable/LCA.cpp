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

const int N = 100005, M = 22;
int tab[N][M];
vector<int> graph[N];

int par[N], depth[N] = {0};

void dfs(int curr, int p){
    par[curr] = p;
    for(auto &nbr : graph[curr]){
        if(nbr != p){
            depth[nbr] = 1 + depth[curr];
            dfs(nbr, curr);
        }
    }
}

int lca_with_two_pointer(int x, int y){
    if(depth[x] < depth[y]){
        swap(x, y);
    }
    if(x == y) return x;

    // always depth of x is more
    while(depth[x] == depth[y]){
        x = par[x];
    }
    while(x != y){
        x = par[x];
        y = par[y];
    }
    return x;
}

void preprocess_sparsetable(int curr, int p){
    tab[curr][0] = p;
    for(int j = 1; j < M; j++){
        tab[curr][j] = tab[tab[curr][j-1]][j-1];
    }
    for(auto &nbr : graph[curr]){
        if(nbr != p){
            depth[nbr] = 1 + depth[curr];
            preprocess_sparsetable(nbr, curr);
        }
    }
}

int lca_with_sparse(int x, int y){
    if(x == y) return x;
    if(depth[x]  < depth[y]){
        swap(x, y);
    }

    int diff = depth[x] - depth[y];
    for(int i = M-1 ; i >= 0 ; i--){
        if((diff >> i) & 1){
            x = tab[x][i];
        }
    }
    if(x == y) return x;

    for(int i = M-1 ; i >= 0 ; i--){
        if(tab[x][i] != tab[y][i]){
            x = tab[x][i];
            y = tab[y][i];
        }
    }
    return tab[x][0];
}

void solve() {
    int n;
    cin >> n;
    loop(i, 1, n){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
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