// Problem Link -> https://cses.fi/problemset/task/1144
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

struct segtree {
    size_t size;
    vector<vi> nodes;
    size_t diff;

    void init(ll n){
        size = 1;
        while(size < n) size *= 2;
        diff = size - n;
        nodes.assign(2*size, vi());
    }

    void build(vi &arr, ll idx, ll lx, ll rx){
        if(rx - lx == 1){
            nodes[idx] = {arr[lx]};
            return;
        }
        ll m = lx + (rx - lx) / 2;
        build(arr, 2*idx+1, lx, m);
        build(arr, 2*idx+2, m, rx);

        // Combining the result
        nodes[idx].clear();
        
        auto left = nodes[2*idx+1];
        auto right = nodes[2*idx+2];
    
        merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(nodes[idx]));
    }

    void build(vi &arr){
        build(arr, 0, 0, size);
    }

    void set(ll k, ll x, ll idx, ll lx, ll rx){
        if(rx-lx == 1){
            nodes[idx] = {x};
            return;
        }
        ll m = lx + (rx - lx) / 2;
        if(k < m){
            set(k, x, 2*idx+1, lx, m);
        } else {
            set(k, x, 2*idx+2, m, rx);
        }

        // Combining the result

        nodes[idx].clear();

        auto left = nodes[2*idx+1];
        auto right = nodes[2*idx+2];
    
        merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(nodes[idx]));
    }

    void set(ll k, ll x){
        set(k, x, 0, 0, size);
    }

    ll getCount(ll a, ll b){
        auto start_idx = lower_bound(nodes[0].begin(), nodes[0].end(), a);
        auto end_idx = upper_bound(nodes[0].begin(), nodes[0].end(), b);

        return end_idx - start_idx;
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vi arr(n);
    loop(i, 0, n){
        cin >> arr[i];
    }
    segtree st;
    st.init(n);
    st.build(arr);
    while(q--){
        char op;
        cin >> op;
        if(op == '!'){
            ll k, x;
            cin >> k >> x;
            st.set(k, x);
        } else {
            ll a, b;
            cin >> a >> b;
            cout << st.getCount(a, b) << "\n";
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