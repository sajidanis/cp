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

bool isValidPos(int row, int col, int n){
    return row >= 0 and col >= 0 and row < n and col < n;
}

bool isSafe(vector<vector<bool>> &board, int n, int row, int col){
    if(isValidPos(row - 2, col - 1, n) && board[row-2][col-1]){
        return false;
    }

    if(isValidPos(row - 2, col + 1, n) && board[row-2][col+1]){
        return false;
    }

    if(isValidPos(row - 1, col - 2, n) && board[row-1][col-2]){
        return false;
    }

    if(isValidPos(row - 1, col + 2, n) && board[row-1][col+2]){
        return false;
    }
    return true;
}
ll ways = 0;

void nknights(ll sr, ll sc, ll placed, ll n, vector<vector<bool>> &board){
    if(placed == n){
        ways++;
        return;
    }

    for(ll row = sr; row < n ; row++){
        for(ll col = (row == sr ? sc : 0); col < n ; col++){
            if(not board[row][col] && isSafe(board, n, row, col)){
                board[row][col] = true;
                nknights(row, col+1, placed+1, n, board);
                board[row][col] = false;
            }
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    nknights(0, 0, 0, n, board);
    cout << ways;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    cin >> t;
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