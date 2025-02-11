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
ll ans = 0;
void famtree(ll root, ll par, vector<vi> &tree, vi &w, vi &ma, vi &mi){
    for(ll child : tree[root]){
        if(child != par){
            famtree(child, root, tree, w, ma, mi);
            ma[root] = max(ma[root], ma[child]);
            mi[root] = min(mi[root], mi[child]);
        }
    }

    ma[root] = max(ma[root], w[root]);
    mi[root] = min(mi[root], w[root]); 

    ans = max(ans, abs(w[root] - ma[root]));
    ans = max(ans, abs(w[root] - mi[root]));
}

void solve() {
    ll n, root = 0;
    cin >> n;
    vi mi(n, INT_MAX);
    vi ma(n, INT_MIN);
    vi w(n);
    vi p(n);
    vector<vi> tree;
    loop(i, 0, n){
        cin >> w[i];
    }
    tree.assign(n+1, vi());
    loop(i, 0, n){
        cin >> p[i];
        if(p[i] == -1){
            root = i;
        } else {
            tree[p[i]].push_back(i);
        }
    }
    famtree(root, -1, tree, w, ma, mi);
    cout << ans;
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