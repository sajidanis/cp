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

template<class T>
class matrix{
    public :
    vector<vector<T>> mat;
    size_t r, c;

    matrix(size_t rows, size_t cols, T initValue) : r(rows), c(cols){
        mat.resize(r, vector<T>(c, initValue));
    }

    matrix operator*(const matrix<T> &b) const {
        matrix<T> res(r, b.c, 0);
        for(int i=0; i<r; i++){
            for(int j=0; j<b.c; j++){
                for(int k=0; k<c; k++){
                    res.d[i][j] += ((mat[i][k]%MOD)*(b.mat[k][j]%MOD));
                    res.d[i][j] %= MOD;
                }
            }
        }
        return res;
    } 
    friend istream &operator>>(istream &in, matrix<T> &m){
        char x;
        for(ll i = 0 ; i < m.r ; i++){
            loop(j, 0, m.c){
                in >> x;
                m.mat[i][j] = x == '*';
            }
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, matrix<T> &m){
        for(ll i = 0 ; i < m.r ; i++){
            loop(j, 0, m.c){
                out << m.mat[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }
};

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

ll n_queen(ll r, vi &col, vi &diag1, vi &diag2, ll &ways, ll n, matrix<bool> &reserved){
    if(r == n){
        ways++;
        return ways;
    }
    loop(c, 0, n){
        if(col[c] || diag1[r+c] || diag2[r-c+n-1] || reserved.mat[r][c]) continue;
        col[c] = 1;
        diag1[r+c] = 1;
        diag2[r-c+n-1] = 1;
        n_queen(r+1, col, diag1, diag2, ways, n, reserved);
        col[c] = 0;
        diag1[r+c] = 0;
        diag2[r-c+n-1] = 0;
    }
    return ways;
}
 
void solve(){
    matrix<bool> data(8, 8, false);
    cin >> data;
    ll n = 8;
    vi col(n, 0);
    vi diag1(2*n-1, 0), diag2(2*n-1, 0);
    ll ways = 0;
    ll cnt = n_queen(0, col, diag1, diag2, ways, n, data);
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