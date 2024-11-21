// Problem Link -> https://codeforces.com/problemset/problem/126/B
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
    freopen("../input", "r", stdin);
    freopen("../output", "w", stdout);
#endif
}
vi pow_table;

ll getRollingHash(char prev, char next, ll p, ll prevHash, ll w){
    return ((prevHash - (prev - 'a' + 1)) / p) + ((next - 'a' + 1) * pow_table[w-1] % mod) % mod;
}

ll calcHash(string str, ll p){
    ll hash = 0;
    loop(i, 0, str.size()){
        hash = (hash + ((str[i] - 'a' + 1) * pow_table[i])) % mod;
    }
    return hash;
}

bool matchPattern(string s, ll hash, ll w){
    ll prevHash = calcHash(s.substr(1, w), 31);
    if(prevHash == hash) return true;
    int n = s.size();
    loop(i, w+1, n-1){
        ll nextHash = getRollingHash(s[i - w], s[i], 31, prevHash, w);
        if(hash == nextHash) return true;
        prevHash = nextHash;
    }
    return false;
}

void solve() {
    string str;
    cin >> str;

    ll n = str.size();

    pow_table.assign(n+1, 0);

    ll p = 31;

    pow_table[0] = 1;
    pow_table[1] = p;

    loop(i, 2, n+1){
        pow_table[i] = (pow_table[i-1] * p) % mod;
    }

    vi indices;
    vi hashes;

    ll pre = 0;
    ll suff = 0;

    loop(i, 0, n){
        pre = (pre + ((str[i] - 'a' + 1) * pow_table[i])) % mod;
        suff = ((suff * p) % mod + (str[n-1-i] - 'a' + 1)) % mod;
        if(pre == suff){
            indices.push_back(i);
            hashes.push_back(pre);
        }
    }
    

    int lo = 0;
    int hi = indices.size()-1;
    string ans = "";
    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if(matchPattern(str, hashes[mid], indices[mid] + 1)){
            lo = mid+1;
            ans = str.substr(0, indices[mid]+1);
        } else {
            hi = mid - 1;
        }
    }

    cout << ((ans.size() > 0) ? ans : "Just a legend\n");

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