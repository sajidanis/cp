// Problem Link -> https://codeforces.com/contest/61/problem/E
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

    void init(ll N){
        size = 1;
        while(size < N) size *= 2;
        nodes.assign(2*size, vi());
    }

    void build(vi &arr, ll idx, ll lx, ll rx){
        if(rx - lx == 1){
            if(lx >= arr.size()){
                nodes[idx] = {};
                return;
            }
            nodes[idx] = {arr[lx]};
            return;
        }

        ll m = lx + (rx - lx)/ 2;
        build(arr, 2*idx+1, lx, m);
        build(arr, 2*idx+2, m, rx);

        // merge in the output array
        nodes[idx].clear();
        merge(
            nodes[2*idx+1].begin(), nodes[2*idx+1].end(),
            nodes[2*idx+2].begin(), nodes[2*idx+2].end(),
            back_inserter(nodes[idx])
        );
    }

    void build(vi &arr){
        build(arr, 0, 0, size);
    }

    ll countSmaller(ll l, ll r, ll key, ll idx, ll lx, ll rx){
        if(l >= rx || r <= lx){
            return 0;
        }
        if(lx >= l and rx <= r){
            auto t = nodes[idx];
            ll ans = upper_bound(t.begin(), t.end(), key) - t.begin();
            return ans;
        }
        ll m = lx + (rx-lx)/2;
        
        return countSmaller(l, r, key, 2*idx+1, lx, m) +
            countSmaller(l, r, key, 2*idx+2, m, rx);
    }

    ll countSmaller(ll l, ll r, ll key){
        return countSmaller(l, r, key, 0, 0, size);
    }

    ll countLarger(ll l, ll r, ll key, ll idx, ll lx, ll rx){
        if(l >= rx || r <= lx){
            return 0;
        }
        if(lx >= l and rx <= r){
            auto t = nodes[idx];
            ll ans = t.end() - upper_bound(t.begin(), t.end(), key);
            return ans;
        }
        ll m = lx + (rx-lx)/2;
        
        return countLarger(l, r, key, 2*idx+1, lx, m) +
            countLarger(l, r, key, 2*idx+2, m, rx);
    }

    ll countLarger(ll l, ll r, ll key){
        return countLarger(l, r, key, 0, 0, size);
    }   

};

void solve() {
    ll n;
    cin >> n;
    vi arr(n);
    loop(i, 0, n){
        cin >> arr[i];
    }
    struct segtree st;
    st.init(n);
    st.build(arr);

    ll ans = 0;

    loop(i, 1, n-1){
        ll s = st.countLarger(0, i, arr[i]);
        ll g = st.countSmaller(i+1, n, arr[i]);
        ans += s*g;
    }
    cout << ans;
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