// Problem Link -> https://codeforces.com/problemset/problem/118/B
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
    ll n;
    cin >> n;

    vector<vector<char>> pattern(2*n + 1, vector<char>(2*n + 1, ' '));

    ll center_pos = n;

    loop(i, 0, n + 1) {
        pattern[i][center_pos] = i + '0';
        loop(j, 0, i){
            pattern[i][center_pos + j + 1] = (char)((i - j - 1) + '0');
            pattern[i][center_pos - (j + 1)] = (char)((i - j - 1) + '0');
        }
    }

    loop_rev(i, 2*n, n){
        loop(j, 0, 2*n + 1){
            pattern[i][j] = pattern[2*n - i][j];
        }   
    }

    for(auto &row : pattern){
        for(auto &el : row){
            cout << el << " ";
        }
        cout << "\n";
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