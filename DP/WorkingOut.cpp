// Problem Link -> https://codeforces.com/problemset/problem/429/B
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
#define vvi             vector<vector<ll>>
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

ll maxCalorie(ll n, ll m, vvi &cal){
    vvi f(n+2, vi(m+2, 0));
    vvi g(n+2, vi(m+2, 0));
    vvi h(n+2, vi(m+2, 0));
    vvi a(n+2, vi(m+2, 0));

    loop(i, 1, n+1){
        loop(j, 1, m+1){
            f[i][j] = max(f[i-1][j], f[i][j-1]) + cal[i][j];
        }
    }

    loop_rev(i, n, 0){
        loop_rev(j, m, 0){
            g[i][j] = max(g[i+1][j], g[i][j+1]) + cal[i][j];
        }
    }

    loop_rev(i, n, 0){
        loop(j, 1, m+1){
            h[i][j] = max(h[i+1][j], h[i][j-1]) + cal[i][j];
        }
    }

    loop(i, 1, n+1){
        loop_rev(j, m, 0){
            a[i][j] = max(a[i][j+1], a[i-1][j]) + cal[i][j];
        }
    }

    ll ans = 0;

    for(int i = 2; i < n; i++){
        for(int j = 2 ; j < m ; j++){
            ans = max(ans, f[i][j-1] + g[i][j+1] + h[i+1][j] + a[i-1][j]);
            ans = max(ans, f[i-1][j] + g[i+1][j] + h[i][j-1] + a[i][j+1]);
        }
    }
    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vvi arr(n+1, vi(m+1, 0));

    loop(i, 1, n+1){
        loop(j, 1, m+1){
            cin >> arr[i][j];
        }
    }

    cout << maxCalorie(n, m, arr);

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