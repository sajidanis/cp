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
#define pb              push_back
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
    freopen("/home/sajid/Documents/cp/input", "r", stdin);
    freopen("/home/sajid/Documents/cp/output", "w", stdout);
#endif
}

void solve() {
    ll m, n, x;
    cin >> m >> n;

    vi rows(m, -1);
    vi cols(n, -1);

    vector<vi> matB(m, vi(n));
    vector<vi> matA(m, vi(n, 1));
    
    loop(i, 0, m){
        loop(j, 0, n){
            cin >> x;
            matB[i][j] = x;
            if (x == 0) {
                loop(k, 0, n) {
                    matA[i][k] = 0;
                }
                loop(k, 0, m) {
                    matA[k][j] = 0;
                }
            }
            
        }
    }

    // Step 3: Recompute B' from A
    vector<vector<int>> B_prime(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        bool row_or = false;
        for (int k = 0; k < n; ++k)
            if (matA[i][k] == 1) {
                row_or = true;
                break;
            }
        for (int j = 0; j < n; ++j) {
            bool col_or = false;
            for (int k = 0; k < m; ++k)
                if (matA[k][j] == 1) {
                    col_or = true;
                    break;
                }
            B_prime[i][j] = (row_or || col_or) ? 1 : 0;
        }
    }

    // Step 4: Compare B' with original B
    bool valid = true;
    for (int i = 0; i < m && valid; ++i)
        for (int j = 0; j < n && valid; ++j)
            if (matB[i][j] != B_prime[i][j])
                valid = false;

    // Step 5: Output result
    if (!valid) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matA[i][j] << (j == n - 1 ? '\n' : ' ');
            }
        }
    }
    return;
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