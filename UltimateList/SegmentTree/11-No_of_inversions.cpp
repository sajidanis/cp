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
    freopen("../../input", "r", stdin);
    freopen("../../output", "w", stdout);
#endif
}

struct node{
    ll inversions = 0;
    ll freq[41] = {0};
};

struct segtree{
    vector<node> tree;
    ll size;


    void init(ll n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2 * size, {{0}, {0}});
    }

    void build(vi &arr){
        build(arr, 0, 0, size);
    }

    void build(vi &arr, ll idx, ll lx, ll rx){
        if(rx - lx == 1){
            if(lx >= arr.size()){
                return;
            }
            tree[idx].freq[arr[lx]] = 1;
            tree[idx].inversions = 0;
            return;
        }

        ll mid = lx + (rx - lx) / 2;
        build(arr, 2 * idx + 1, lx, mid);
        build(arr, 2 * idx + 2, mid, rx);

        tree[idx].inversions = tree[2*idx+1].inversions + tree[2*idx+2].inversions;

        for(ll i = 0; i < 41; i++){
            for(ll j = i+1; j < 41; j++){
                tree[idx].inversions += tree[2*idx+1].freq[j] * tree[2*idx+2].freq[i];
            }
            tree[idx].freq[i] = tree[2 * idx + 1].freq[i] + tree[2 * idx + 2].freq[i];
        }
    }

    void update(ll x, ll v){
        update(x, v, 0, 0, size);
    }

    void update(ll x, ll v, ll idx, ll lx, ll rx){
        if(rx - lx == 1 and lx == x){
            memset(tree[idx].freq, 0, sizeof(tree[idx].freq));
            tree[idx].freq[v] = 1;
            return;
        }

        ll mid = lx + (rx - lx) / 2;
        if(x < mid){
            update(x, v, 2*idx+1, lx, mid);
        } else {
            update(x, v, 2*idx+2, mid, rx);
        }

        tree[idx].inversions = tree[2*idx+1].inversions + tree[2*idx+2].inversions;

        for(ll i = 0; i < 41; i++){
            for(ll j = i+1; j < 41; j++){
                tree[idx].inversions += tree[2*idx+1].freq[j] * tree[2*idx+2].freq[i];
            }
            tree[idx].freq[i] = tree[2 * idx + 1].freq[i] + tree[2 * idx + 2].freq[i];
        }
    }

    node query(ll l, ll r){
        return query(l, r, 0, 0, size);
    }

    node query(ll l, ll r, ll idx, ll lx, ll rx){
        if(l >= rx or r <= lx) return {{0}, {0}};

        if(l <= lx and r >= rx) return tree[idx];

        ll mid = lx + (rx - lx) / 2;
        node left = query(l, r, 2*idx+1, lx, mid);
        node right = query(l, r, 2*idx+2, mid, rx);

        node res;
        res.inversions = left.inversions + right.inversions;

        for(ll i = 0; i < 41; i++){
            for(ll j = i+1; j < 41; j++){
                res.inversions += left.freq[j] * right.freq[i];
            }
            res.freq[i] = left.freq[i] + right.freq[i];
        }

        return res;
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
        ll option;
        cin >> option;
        switch(option){
            case 1:
                ll l, r;
                cin >> l >> r;
                cout << st.query(l-1, r).inversions << "\n";
                break;
            case 2:
                ll x, v;
                cin >> x >> v;
                st.update(x-1, v);
                break;
        }
    }

}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    // cin >> t;
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