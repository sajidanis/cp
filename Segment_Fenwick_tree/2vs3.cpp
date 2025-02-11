// Problem Link -> https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3/
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
    vi arr;
    size_t apnd;

    void init(ll N){
        size = 1;
        apnd = 0;
        while(size < N) size *= 2;
        arr.assign(2*size, 0);
    }

    void build(string &bin, ll idx, ll lx, ll rx){
        if(rx-lx == 1){
            arr[idx] = bin[lx];
            return;
        }
        ll mid = lx + ((rx - lx) / 2);
        
        build(bin, 2*idx+1, lx, mid);
        build(bin, 2*idx + 2, mid, rx);

        // build the upcoming tree
        arr[idx] = (2*arr[2*idx+1] + arr[2*idx+2]) % 3;
    }

    void build(string &bin){
        ll n = bin.size();
        apnd = size - n;
        string temp = "";
        loop(i, 0, apnd){
            temp += "0";
        }
        string new_bin = temp + bin;
        build(new_bin, 0, 0, size);
    }

    void set(ll i, ll idx, ll lx, ll rx){
        if(rx - lx == 1){
            if(arr[idx] == 0){
                arr[idx] = 1;
            }
            return;
        }

        ll mid = lx + (rx - lx) / 2;

        if(i < mid){
            set(i, 2*idx+1, lx, mid);
        } else {
            set(i, 2*idx+2, mid, rx);
        }

        // build the upcoming tree
        arr[idx] = (2*arr[2*idx+1] + arr[2*idx+2])  % 3;

    }

    void set(ll i){
        set(i+apnd, 0, 0, size);
    }

    ll value(ll l, ll r, ll idx, ll lx, ll rx){
        if(l >= rx || r <= lx){
            return 0;
        }
        if(lx >= l && rx <= r){
            return arr[idx];
        }
        
        ll mid = lx + (rx - lx) / 2;

        auto t1 = value(l, r, 2*idx+1, lx, mid);
        auto t2 = value(l, r, 2*idx+2, mid, rx);

        return (2*t1 + t2) % 3;
    }

    ll value(ll l, ll r){
        return value(l + apnd, r+apnd+1, 0, 0, size);
     }
};

void solve() {
    ll N, Q;
    cin >> N;
    string bin;
    cin >> bin;

    segtree st;

    st.init(N);
    st.build(bin);
    cin >> Q;
    while(Q--){
        int t;
        cin >> t;
        switch (t)
        {
        case 0:
            int l, r;
            cin >> l >> r;
            cout << st.value(l, r) << "\n";
            break;
        case 1:
            int i;
            cin >> i;
            st.set(i);
        default:
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