// Problem Link -> https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/
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

void solve() {
    ll n, m, q, a, b;
    cin >> n >> m;
    vector<ll> arr(n+2, 0);
    for(ll i = 0 ; i < m ; i++){
        cin >> a >> b;
        arr[a] += 1;
        arr[b+1] -= 1;
    }
    vi counts(n+2, 0);
    
    counts[arr[0]]++;
    for(ll i = 1 ; i <= n ; i++){
        arr[i] += arr[i-1];
        counts[arr[i]]++;
    }

    for(ll i = n-1; i >= 0 ; i--){
        counts[i] += counts[i+1];
    }

    cin >> q;
    ll x;
    for(ll i = 0 ; i < q ; i++){
        cin >> x;
        cout << counts[x] << "\n";
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