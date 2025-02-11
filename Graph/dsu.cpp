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

struct dsu{
    vector<ll> parents;
    vector<ll> rank;

    void init(size_t N){
        parents.reserve(N);
        rank.assign(N, 0);

        loop(i, 0, N){
            parents[i] = i;
        }
    }

    ll find_set(ll v){
        if(v == parents[v]){
            return v;
        }
        return parents[v] = find_set(parents[v]);
    }

    void union_sets(ll a, ll b){
        a = find_set(a);
        b = find_set(b);

        if(a == b) return;
        
        if(rank[a] < rank[b]){
            swap(a, b);
        }

        parents[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
    }
};

void solve() {

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