// Problem Link -> https://leetcode.com/problems/rotting-oranges/description/
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

vector<list<ll>> graph;

void bfs(int src, int v){
    queue<ll>  qu;
    vector<bool> vis(v, false);
    qu.push(src);
    vis[src] = true;

    while(!qu.empty()){
        ll cur = qu.front();
        qu.pop();
        cout << cur << " ";
        for(auto nbr : graph[cur]){
            if(not vis[nbr]){
                vis[nbr] = true;
                qu.push(nbr);
            }
        }
    }
}

bool isSafe(ll i, ll j, ll m, ll n, vector<vi> &g){
    return i >= 0 and j >= 0 and i < m and j < n and g[i][j] == 1 and g[i][j] != 2;
}

vi addEdge(ll i, ll j, ll m, ll n, vector<vi> &grid, ll *fresh){
    vi temp;
    if(isSafe(i, j+1, m, n, grid)){
        temp.push_back((m*i+j+1));
        *fresh -= 1;
        grid[i][j+1] = 2;
    }
    if(isSafe(i, j-1, m, n, grid)){
        temp.push_back((m*i)+(j-1));
        *fresh -= 1;
        grid[i][j-1] = 2;
    }
    if(isSafe(i-1, j, m, n, grid)){
        temp.push_back((m*(i-1)+(j)));
        *fresh -= 1;
        grid[i-1][j] = 2;
    }
    if(isSafe(i+1, j, m, n, grid)){
        temp.push_back((m*(i+1)+(j)));
        *fresh -= 1;
        grid[i+1][j] = 2;
    }
    return temp;
}

void solve() {
    ll n, m;
    cin >> m >> n;
    vector<vi> grid(m, vi(n, 0));

    ll fresh = 0;

    vi rottenList;
  
    loop(i, 0, m){
        loop(j, 0, n){
            cin >> grid[i][j];
            if(grid[i][j] == 2){
                rottenList.push_back(m*i+j);
            }
            fresh += grid[i][j] == 1;
        }   
    }
    if(rottenList.empty()){
        cout << 0;
        return;
    }
    ll counter = 0;
    vi temp;
    while(true){
        while(!rottenList.empty()){
            ll i = 0;
            ll j = 0;
            ll val = rottenList.back();
            rottenList.pop_back();
            i = val / m;
            j = val % m;

            // Corresponding to this i and j add all the fresh oranges into the rotten

            auto res = addEdge(i, j, m, n, grid, &fresh);

            for(auto &el : res){
                temp.push_back(el);
            }   
        }
        counter++;
        if(fresh <= 0 or temp.empty()){
            break;
        }
        rottenList = temp;
        temp.clear();
    }

    
    if(fresh > 0){
        cout << -1;
        return;
    } 
    cout << counter;
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