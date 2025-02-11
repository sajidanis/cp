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


struct segtree {
    ll size;
    vi sums;
    void init(ll n){
        size = 1;
        while(size < n) size *= 2;
        sums.assign(2*size, 0);
    }

    void build(vi &arr, ll x, ll lx, ll rx){
        if(rx-lx == 1){
            if(lx < arr.size()){
                sums[x] = arr[lx];
            }
            return;
        }

        ll m = (lx + rx) / 2;
        build(arr, 2*x+1, lx, m);
        build(arr, 2*x+2, m, rx);

        sums[x] = sums[2*x+1] + sums[2*x+2];
    }
    
    void build(vi &arr){
        build(arr, 0, 0, size);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(rx - lx == 1){
            sums[x] = v;
            return;
        }

        ll m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2*x+1, lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }

        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void set(ll i, ll v){
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) {
            return 0;
        }
        if(lx >= l && rx <= r){
            return sums[x];
        }

        int m = (lx + rx) / 2;

        ll s1 = sum(l, r, 2*x + 1, lx, m);
        ll s2 = sum(l, r, 2*x + 2, m, rx);
        return s1 + s2;
    }

    ll sum(int l, int r){
        return sum(l, r, 0, 0, size);

    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    segtree st;
    st.init(n);

    /** This is the optimized segment tree creation in linear time */
    vi arr(n);
    for(int i = 0 ; i < n ; i++ ){
        cin >> arr[i];
    }

    st.build(arr);

    /** n log n time for building the segment tree  so need to build the tree in linear time */
    // for(int i = 0 ; i < n; i++){
    //     ll v;
    //     cin >> v;
    //     st.set(i, v);
    // }
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else{
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << "\n";
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