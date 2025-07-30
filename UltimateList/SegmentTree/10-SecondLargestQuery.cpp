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

struct info{
    ll largest = -1;
    ll second_largest = -1;

    ll larg_freq = 0;
    ll slarg_freq = 0;

    info(ll l, ll sl, ll l_f, ll sl_f) : largest(l), second_largest(sl), larg_freq(l_f), slarg_freq(sl_f) {}
};

struct segtree{
    size_t size;
    vector<info> tree;

    void init(ll n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2 * size, {-1, -1, 0, 0});
    }

    void build(vi &arr, ll idx, ll lx, ll rx){
        if(rx - lx == 1){
            if(lx >= arr.size()){
                return;
            }
            tree[idx] = {arr[lx], -1, 1, 0};
            return;
        }

        ll mid = lx + (rx - lx) / 2;

        build(arr, 2*idx+1, lx, mid);
        build(arr, 2*idx+2, mid, rx);

        // merge the results for the parent
        info i1 = tree[2*idx+1];
        info i2 = tree[2*idx+2];
        vi temp = {i1.largest, i1.second_largest, i2.largest, i2.second_largest};
        sort(temp.begin(), temp.end());

        auto last = std::unique(temp.begin(), temp.end());
        temp.erase(last, temp.end());

        auto sz = temp.size();

        tree[idx].largest = temp[sz-1];
        tree[idx].larg_freq = 0;

        if(i1.largest == temp[sz-1]) tree[idx].larg_freq += i1.larg_freq;
        if(i1.second_largest == temp[sz-1]) tree[idx].larg_freq += i1.slarg_freq;
        if(i2.largest == temp[sz-1]) tree[idx].larg_freq += i2.larg_freq;
        if(i2.second_largest == temp[sz-1]) tree[idx].larg_freq += i2.slarg_freq;

        if(sz < 2){
            tree[idx].second_largest = -1;
            tree[idx].slarg_freq = 0;
            return;
        }

        tree[idx].second_largest = temp[sz-2];
        tree[idx].slarg_freq = 0;
        // calculate the frequencies
        if(i1.largest == temp[sz-2]) tree[idx].slarg_freq += i1.larg_freq;
        if(i1.second_largest == temp[sz-2]) tree[idx].slarg_freq += i1.slarg_freq;
        if(i2.largest == temp[sz-2]) tree[idx].slarg_freq += i2.larg_freq;
        if(i2.second_largest == temp[sz-2]) tree[idx].slarg_freq += i2.slarg_freq;
    }

    void build(vi &arr){
        build(arr, 0, 0, size);
    }

    void update(ll p, ll x, ll idx, ll lx, ll rx){
        if(rx - lx == 1 and lx == p){
            tree[idx].largest = x;
            return;
        }

        ll mid = lx + (rx - lx) / 2;
        if(p < mid){
            update(p, x, 2*idx+1, lx, mid);
        } else {
            update(p, x, 2*idx+2, mid, rx);
        }
        
        // merge the results for the parent
        info i1 = tree[2*idx+1];
        info i2 = tree[2*idx+2];
        vi temp = {i1.largest, i1.second_largest, i2.largest, i2.second_largest};
        sort(temp.begin(), temp.end());

        auto last = std::unique(temp.begin(), temp.end());
        temp.erase(last, temp.end());

        auto sz = temp.size();

        tree[idx].largest = temp[sz-1];
        tree[idx].larg_freq = 0;

        if(i1.largest == temp[sz-1]) tree[idx].larg_freq += i1.larg_freq;
        if(i1.second_largest == temp[sz-1]) tree[idx].larg_freq += i1.slarg_freq;
        if(i2.largest == temp[sz-1]) tree[idx].larg_freq += i2.larg_freq;
        if(i2.second_largest == temp[sz-1]) tree[idx].larg_freq += i2.slarg_freq;

        if(sz < 2){
            tree[idx].second_largest = -1;
            tree[idx].slarg_freq = 0;
            return;
        }

        tree[idx].second_largest = temp[sz-2];
        tree[idx].slarg_freq = 0;
        // calculate the frequencies
        if(i1.largest == temp[sz-2]) tree[idx].slarg_freq += i1.larg_freq;
        if(i1.second_largest == temp[sz-2]) tree[idx].slarg_freq += i1.slarg_freq;
        if(i2.largest == temp[sz-2]) tree[idx].slarg_freq += i2.larg_freq;
        if(i2.second_largest == temp[sz-2]) tree[idx].slarg_freq += i2.slarg_freq;

    }

    void update(ll p, ll x){
        update(p, x, 0, 0, size);
    }

    info getSecondLargest(ll l, ll r, ll idx, ll lx, ll rx){
        if(lx >= l and rx <= r){
            return tree[idx];
        }
        if(l >= rx or r <= lx) return {-1, -1, 0, 0};

        ll mid = lx + (rx - lx) / 2;

        auto i1 = getSecondLargest(l, r, 2*idx+1, lx, mid);
        auto i2 = getSecondLargest(l, r, 2*idx+2, mid, rx);
        
        vi temp = {i1.largest, i1.second_largest, i2.largest, i2.second_largest};
        sort(temp.begin(), temp.end());

        info res_tree = {-1, -1, 0, 0};

        auto last = std::unique(temp.begin(), temp.end());
        temp.erase(last, temp.end());

        auto sz = temp.size();

        res_tree.largest = temp[sz-1];
        res_tree.larg_freq = 0;

        if(i1.largest == temp[sz-1]) res_tree.larg_freq += i1.larg_freq;
        if(i1.second_largest == temp[sz-1]) res_tree.larg_freq += i1.slarg_freq;
        if(i2.largest == temp[sz-1]) res_tree.larg_freq += i2.larg_freq;
        if(i2.second_largest == temp[sz-1]) res_tree.larg_freq += i2.slarg_freq;

        if(sz < 2){
            res_tree.second_largest = -1;
            res_tree.slarg_freq = 0;
            return res_tree;
        }

        res_tree.second_largest = temp[sz-2];
        res_tree.slarg_freq = 0;
        // calculate the frequencies
        if(i1.largest == temp[sz-2]) res_tree.slarg_freq += i1.larg_freq;
        if(i1.second_largest == temp[sz-2]) res_tree.slarg_freq += i1.slarg_freq;
        if(i2.largest == temp[sz-2]) res_tree.slarg_freq += i2.larg_freq;
        if(i2.second_largest == temp[sz-2]) res_tree.slarg_freq += i2.slarg_freq;

        return res_tree;
    }

    ll getSecondLargest(ll l, ll r){
        return getSecondLargest(l, r, 0, 0, size).slarg_freq;
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
                ll p, x;
                cin >> p >> x;
                st.update(p-1, x);
                break;
            case 2:
                ll l, r;
                cin >> l >> r;
                cout << st.getSecondLargest(l-1, r) << "\n";
                break;
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