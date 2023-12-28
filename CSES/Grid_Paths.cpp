// Problem Link ==> 
/* Md Sajid Anis */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// using namespace __gnu_pbds;
 
using namespace std;
 
#define  ll   long long
#define  ld   long double
#define  pi   pair<ll,ll>
#define  pd   pair<double,double>
#define  vi   vector<ll>
#define  vs   vector<string>
#define  vvi  vector<vector<ll> > 
#define  vvp  vector<vector<pi> >
#define  vp   vector<pi>
#define  ump  unordered_map
#define  MOD  1000000007
#define  eps  1e-12
#define  loop(i,s,e) for(ll i = (s); i < (e); i++)
#define  forsn(i,s,e) for(ll i = (s); i <= (e); i++)
#define  rloop(i,s,e) for(ll i = (s); i > (e); i--)
#define  rforsn(i,s,e) for(ll i = (s); i >= (e); i--)
#define  iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define  endl "\n"
#define  dbg(x) cout<<#x<<" = "<<x<<ln
#define  mp make_pair
#define  pb emplace_back
#define  ff first
#define  ss second
#define  INF 1e18
#define  pq_max priority_queue<ll>
#define  pq_min priority_queue<ll, vector<ll>, greater<ll>>
#define  fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define  all(x) (x).begin(), (x).end()
#define  sz(x) ((ll)(x).size())
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
 
#define log(args...)                         \
{                                            \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
}
#define logarr(arr, a, b)                                  \
 for (ll z = (a); z <= (b); z++) cout << (arr[z]) << " "; \
 cout << endl;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}

void file_io(){
    fast_cin();
    #ifndef ONLINE_JUDGE
            freopen("input", "r", stdin);
            freopen("output", "w", stdout);
    #endif
}

pi getNewPoints(ll r, ll c, char path){
    if(path == 'D' || path == 'd'){
        return {r+1, c};
    }
    if(path == 'U' || path == 'u'){
        return {r-1, c};
    }
    if(path == 'L' || path == 'l'){
        return {r, c-1};
    }
    if(path == 'R' || path == 'r'){
        return {r, c+1};
    }
}

bool check(vvi &grid, ll size){
    loop(i, 0, size){
        loop(j, 0, size){
            if(grid[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}
ll pathLength = 48;

void findTotalPaths(ll idx, ll r, ll c, ll &ways, vvi &grid, vector<char> &paths, ll size){
    if(grid[size-1][0] == 1 && check(grid, size)){
        ways += 1;
        return;
    }
    if(idx == pathLength){
        return;
    }

    for(auto &el : paths){
        auto [new_r, new_c] = getNewPoints(r, c, el);
        if(new_r > size-1 || new_r < 0 || new_c > size-1 || new_c < 0 || grid[new_r][new_c]){
            continue;
        }
        grid[new_r][new_c] = 1;
        findTotalPaths(idx+1, new_r, new_c, ways, grid, paths, size);
        grid[new_r][new_c] = 0;
    }

}
 
void solve(){
    string s;
    cin >> s;
    ll size = 7;
    vvi grid(size, vi(size, 0));
    grid[0][0] = 1;
    vector<char> paths = {'D', 'U', 'L', 'R'};
    ll ways = 0;
    findTotalPaths(0, 0, 0, ways, grid, paths, size);
    cout << ways;
}
 
int main()
{
    clock_t begin = clock();
    file_io();
    ll t = 1;
    // cin >> t;
    while(t--){
            solve();
            cout << endl;
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cerr << "\n[Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms]\n";
#endif
    return 0;
}