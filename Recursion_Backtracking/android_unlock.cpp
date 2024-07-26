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
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
}

ll via[10][10];

ll helper(vector<bool> &visited, ll cur, ll remaining){
    if(remaining < 0) return 0;
    if(remaining == 0) return 1;

    visited[cur] = true;

    ll result = 0;

    for(ll i = 1; i <= 9; i++){
        if(not visited[i] and (via[cur][i] == 0 or visited[via[cur][i]])){
            result += helper(visited, i, remaining - 1);
        }
    }
    visited[cur] = false;
    return result;
}

ll numberofPatterns(ll m, ll n){
    memset(via, 0, sizeof(via));

    via[1][3] = via[3][1] = 2;
    via[1][7] = via[7][1] = 4;
    via[7][9] = via[9][7] = 8;
    via[3][9] = via[9][3] = 6;

    via[1][9] = via[9][1] = via[3][7] = via[7][3] = via[2][8] = via[8][2] = via[4][6] = via[6][4] = 5;

    vector<bool> visited(10, false);

    ll ways = 0;
    for(ll i = m ; i <= n; i++){
        ways += helper(visited, 1, i-1) * 4; // 1, 3, 7, 9
        ways += helper(visited, 2, i-1) * 4;
        ways += helper(visited, 5, i-1) ;
    }

    return ways;
}

void solve() {
    ll m, n;
    cin >> m >> n;
    cout << numberofPatterns(m, n);
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