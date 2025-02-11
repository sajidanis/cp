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

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(auto &el : v){
        os << el << "";
    }
    return os;
}
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

vi diag0, diag1, cols;

bool isSafe(vector<vector<bool>> &board, int row, int col){
    ll n = board.size();
    for(ll i = row - 1 ; i >= 0 ; i-- ){
        if(board[i][col]) return false;
    }

    for(int i = row - 1, j = col - 1 ; i >= 0 and j >= 0 ; i--, j--){
        if(board[i][j]) return false;
    }

    for(int i = row - 1, j = col + 1 ; i >= 0 and j < n ; i--, j++){
        if(board[i][j]) return false;
    }
    return true;
} 

ll ways = 0;

void nqueen(ll n, ll i, vector<vector<bool> > &board){
    if(i == n){
        ways++;
        return;
    }

    for(int j = 0 ; j < n; j++){
        if(isSafe(board, i, j)){
            board[i][j] = true;
            nqueen(n, i+1, board);
            board[i][j] = false;
        }
    }
}

void solve() {
    ll n;
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));

    nqueen(n, 0, board);

    cout << ways;
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