// Problem Link -> https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
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

    void init(ll N){
        size = 1;
        while(size < N) size *= 2;
        arr.assign(2*size, 0);
    }

    void set(ll i, ll v, ll idx, ll lx, ll rx){
        if(rx - lx == 1){
            arr[idx] = v;
            return;
        }

        ll m = lx + (rx - lx) / 2;
        if(i < m){
            set(i, v, 2*idx+1, lx, m);
        } else {
            set(i, v, 2*idx+2, m, rx);
        }

        arr[idx] = arr[2*idx+1] + arr[2*idx+2];
    }

    void set(ll i, ll v){
        set(i, v, 0, 0, size);
    }

    ll compute(ll l, ll r, ll idx, ll lx, ll rx){
        if(l >= rx || r <= lx){
            return 0;
        }

        if(lx >= l and r >= rx){
            return arr[idx];
        }

        ll m = lx + (rx - lx)/2;

        auto t1 = compute(l, r, 2*idx+1, lx, m);
        auto t2 = compute(l, r, 2*idx+2, m, rx);
        return t1 + t2;
    }

    ll compute(ll l, ll r){
        return compute(l, r, 0, 0, size);
    }
};

void solve() {
    ll n;
    cin >> n;

    segtree st;
    st.init(n);

    loop(i, 0, n){
        int x;
        cin >> x;
        cout << st.compute(x, n) << " ";
        st.set(x-1, 1);
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