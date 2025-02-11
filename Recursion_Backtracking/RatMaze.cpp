// Problem Link -> https://www.codechef.com/problems/BPHC03
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

bool isSafe(ll i, ll j, ll n, vector<vi> &board){
    return i >= 0 and j >= 0 and i < n and j < n and board[i][j] == 0;
}

ll dirX[] = {-1, 0, 1, 0};
ll dir_y[] = {0, -1, 0, 1};

ll soveMaze(ll sr, ll sc, ll n, vector<vi> &board ){
    
    if(sr == n-1 and sc == n-1){
        return 1;
    }

    ll res = 0;
    loop(j, 0, 4){
        ll r = sr + dirX[j];
        ll c = sc + dir_y[j];
        if(isSafe(r, c, n, board)){
            board[r][c] = 2;
            res += soveMaze(r, c, n, board);
            board[r][c] = 0;
        }
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vector<vi> board(n, vi(n, 0));

    loop(i, 0, n){
        loop(j, 0, n){
            cin >> board[i][j];
        }
    }

    cout << soveMaze(0, 0, n, board);

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