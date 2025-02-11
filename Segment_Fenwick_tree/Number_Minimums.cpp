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
    vector<pair<ll, ll>> mins;
    void init(ll n){
        size = 1;
        while(size < n) size *= 2;
        mins.assign(2*size, {inf, 1});
    }

    void build(vi &arr, ll idx, ll lx, ll rx){
        if(rx-lx == 1){
            if(lx < arr.size())
                mins[idx] = {arr[lx], 1};
            return;
        }
        ll m = lx + (rx - lx) / 2;
        
        build(arr, 2*idx+1, lx, m);
        build(arr, 2*idx+2, m, rx);

    
        // mins[idx] = std::min(mins[2*idx+1], mins[2*idx+2]);

        auto mi = mins[2*idx+1].first > mins[2*idx+2].first ? mins[2*idx+2] : mins[2*idx+1];
        ll count = mi.second;

        if(mins[2*idx+1].first == mins[2*idx+2].first){
            count = mins[2*idx+1].second + mins[2*idx+2].second; 
        }
        mins[idx] = {mi.first, count};
    }

    void build(vi &arr){
        build(arr, 0, 0, size);
    }

    void set(ll i, ll v, ll idx, ll lx, ll rx){
        if(rx-lx == 1){
            mins[idx] = {v, 1};
            return;
        }
        ll m = lx + (rx - lx) / 2;

        if(i < m){
            set(i, v, 2*idx+1, lx, m);
        } else {
            set(i, v, 2*idx+2, m, rx);
        }

        // mins[idx] = std::min(mins[2*idx+1], mins[2*idx+2]);
        auto mi = mins[2*idx+1].first > mins[2*idx+2].first ? mins[2*idx+2] : mins[2*idx+1];
        ll count = mi.second;

        if(mins[2*idx+1].first == mins[2*idx+2].first){
            count = mins[2*idx+1].second + mins[2*idx+2].second; 
        }
        mins[idx] = {mi.first, count};
    }

    void set(ll i, ll v){
        set(i, v, 0, 0, size);
    }

    pair<ll, ll> getMin(ll l, ll r, ll idx, ll lx, ll rx){
        if(l >= rx || r <= lx){
            return {inf, 1};
        }
        if(lx >= l && rx <= r){
            return mins[idx];
        }

        ll m = lx + (rx - lx) / 2;

        auto m1 = getMin(l, r, 2*idx+1, lx, m);
        auto m2 = getMin(l, r, 2*idx+2, m, rx);

        auto mi = m1.first > m2.first ? m2 : m1;
        ll count = mi.second;

        if(m1.first == m2.first){
            count = m1.second + m2.second; 
        }

        return {mi.first, count};
    }

    pair<ll, ll> getMin(ll l, ll r){
        return getMin(l, r, 0, 0, size);
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);

    vi arr(n);
    loop(i, 0, n){
        cin >> arr[i];
    }

    // build the segtree
    st.build(arr);

    // form the queries
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int x, y;
            cin >> x >> y;
            st.set(x, y);
        } else {
            int l, r;
            cin >> l >> r;
            auto res = st.getMin(l, r);
            cout << res.first << " " << res.second << "\n";
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