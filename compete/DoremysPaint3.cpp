// Problem Link ==> 
/* Md Sajid Anis */
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
#define  vvp  vector<vector<pii> >
#define  vp   vector<pii>
#define  ump  unordered_map
#define  MOD  1000000007
#define  eps  1e-12
#define  loop(i,e) for(ll i = 0; i < (e); i++)
#define  forsn(i,s,e) for(ll i = (s); i <= (e); i++)
#define  rloop(i,s) for(ll i = (s); i > 0; i--)
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

void file_io(){
    fast_cin();
    #ifndef ONLINE_JUDGE
            freopen("input", "r", stdin);
            freopen("output", "w", stdout);
    #endif
}
 
void solve(){
    ll n;
    cin >> n;
    vi arr(n);

    ll f = -1;
    ll s = -1;

    map<int, int> m;

    loop(i, n){
        cin >> arr[i];
        m[arr[i]]++;
    }
    if(m.size() > 2){
        cout << "No";
        return;
    }

    f = m[arr[0]];
    if(f == n/2 || f == n/2 + 1 || f == n ){
        cout << "Yes";
    } else {
        cout << "No";
    }

    return;
}
 
int main()
{
    clock_t begin = clock();
    file_io();
    ll t = 0;
    cin >> t;
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