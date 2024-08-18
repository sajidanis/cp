// Problem Link -> https://leetcode.com/problems/surrounded-regions/
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

int dirX[4] = {0, 0, -1, 1};
int dirY[4] = {-1, 1, 0, 0};

void dfs(int i, int j, vector<vector<char>> &b, vector<vector<bool>> &vis){
    int m = b.size();
    int n = b[0].size();
    vis[i][j] = true;
    for(int d = 0 ; d < 4 ; d++){
        int newR = i + dirX[d];
        int newC = j + dirY[d];

        if(newR >= 0 and newC >= 0 and newR < m  and newC < n and b[newR][newC] == 'O' and !vis[newR][newC]){
            dfs(newR, newC, b, vis);
        }
    }
}

void capture(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));

    for(int j = 0 ; j < n ; j++){
        if(board[0][j] == 'O' and (not vis[0][j])){
            dfs(0, j, board, vis);
        }
    }
    if(m > 1){
        for(int j = 0 ; j < n ; j++){
            if(board[m-1][j] == 'O' and (not vis[m-1][j])){
                dfs(m-1, j, board, vis);
            }
        }
    }

    for(int i = 1 ; i < m-1 ; i++){
        if(board[i][0] == 'O' and (not vis[i][0])){
            dfs(i, 0, board, vis);
        }
    }

    if(n > 1){
        for(int i = 1 ; i < m-1 ; i++){
            if(board[i][n-1] == 'O' and (not vis[i][n-1])){
                dfs(i,n-1, board, vis);
            }
        }
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0; j < n ; j++){
            if(!vis[i][j]){
                board[i][j] = 'X';
            }
        }
    }
}

void solve(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));

    loop(i, 0, m){
        loop(j, 0, n){
            cin >> board[i][j];
        }
    }

    capture(board);

    for(auto &row : board){
        for(auto &c : row){
            cout << c << " ";
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