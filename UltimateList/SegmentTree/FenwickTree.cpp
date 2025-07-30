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

struct FenwickTree {
    vi bit;
    size_t size;

    FenwickTree(size_t n){
        this->size = n;
        bit.assign(n, 0);
    }

    FenwickTree(vi const &arr): FenwickTree(arr.size()){
        for(ll i = 0; i < arr.size(); i++){
            bit[i] += arr[i];
            ll r = i | (i+1);
            if(r < this->size) bit[r] += bit[i]; 
        }
    }

    void update(ll idx, ll val){
        for(; idx < size; idx |= (idx + 1)){
            bit[idx] += val;
        }
    }

    ll sum(ll r){
        ll res = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1){
            res += bit[r];
        }
        return res;
    }

    ll range_sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    ll n;
    cin >> n;
    vi arr(n);
    loop(i, 0, n) cin >> arr[i];

    FenwickTree ft(arr);

    cout << ft.range_sum(0, 4) << endl;
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