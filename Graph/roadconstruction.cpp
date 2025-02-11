// Problem Link -> https://cses.fi/problemset/task/1676
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

struct dsu {
    vector<ll> parent;
    vector<ll> size;

    ll numComponents = 0;
    ll maxCompSize = 0;

    void init(size_t N){
        parent.resize(N);
        size.assign(N, 1);

        loop(i, 0, N){
            parent[i] = i;
        }
        numComponents = N;
        maxCompSize = 1;
    }

    ll find_set(ll v){
        if(parent[v] == v){
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    void union_set(ll a, ll b){
        a = find_set(a);
        b = find_set(b);

        if(a == b) return;

        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        maxCompSize = max(maxCompSize, size[a]);
        numComponents -= 1;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    dsu ds;
    ds.init(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        a-- ; b--;
        ds.union_set(a, b);

        cout << ds.numComponents << " " << ds.maxCompSize << "\n";
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