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
int dirX[4] = {0, 1, -1, 0};
int dirY[4] = {1, 0, 0, -1};
int flag = 0;

bool isSafe(int x, int y, vector<vector<int>> &grid, int av_h){
    int m = grid.size();
    int n = grid[0].size();
    return x >= 0 and y >= 0 and x < m and y < n and grid[x][y] != 2 and av_h > 0;
}

bool isSafe(int x, int y, vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    return x >= 0 and y >= 0 and x < m and y < n;
}

void crawl(int x, int y, vector<vector<int>> &grid, int av_h){

    if(x == grid.size()-1 and y == grid[0].size() - 1){
        flag = 1;
        return;
    }
    for(int i = 0 ; i < 4 ;i++){
        if(flag) return;
        int newX = x + dirX[i];
        int newY = y + dirY[i];
        if(isSafe(newX, newY, grid, av_h)){
            auto temp = grid[newX][newY];
            grid[newX][newY] = 2;
            crawl(newX, newY, grid, av_h - temp);
            grid[newX][newY] = temp;
        }
    }
    return;
}

bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp;
    dp.assign(m, vector<int>(n, -1));
    

    dp[0][0] = health - grid[0][0];

    queue<vector<int>> qu;
    qu.push({0, 0, dp[0][0]});

    while(!qu.empty()){
        auto t = qu.front();
        qu.pop();
        int x = t[0];
        int y = t[1];
        int h = t[2];
        if(x == m-1 and y == n-1){
            return true;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dirX[i];
            int ny = y + dirY[i];

            if(isSafe(nx, ny, grid)){
                int new_h = h - grid[nx][ny];
                if(new_h <= 0 ) continue;
                if(new_h > dp[nx][ny]){
                    dp[nx][ny] = new_h;
                    qu.push({nx, ny, new_h});
                }
            }
        }
    }
    return false;
}
void solve() {
    int m, n, h;
    cin >> m >> n >> h;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    loop(i, 0, m){
        loop(j, 0, n){
            cin >> grid[i][j];
        }
    }
    cout << findSafeWalk(grid, h);
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