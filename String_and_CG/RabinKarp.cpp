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
    freopen("../input", "r", stdin);
    freopen("../output", "w", stdout);
#endif
}

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

ll poly_hash(string s, ll p, ll m){
    ll hash_value = 0;
    ll i = 0;
    for(auto &ch : s){
        auto new_val = (ll)((ch-'a') * pow(p, i)) % m;
        hash_value = (hash_value + new_val) % m; 
        i++;
    }
    return hash_value;
}

ll rollingHash(string s, ll prev_hash, ll i, ll j, ll p, ll m){
    if(i == 0){
        return poly_hash(s.substr(i,j), p, m);
    }

    auto new_hash = ((prev_hash - (s[i-1] - 'a')) / p) + ((s[j-1] - 'a') * (ll)(pow(p, (j-i-1))) ) % m;
    return new_hash;
}

bool check(string s, string pat, ll i, ll j){
    ll k = i;
    for(auto &ch : pat){
        if(ch != s[k]){
            return false;
        }
        k++;
    }
    return true;
}

vi rabinKarp(string s, string pat){
    int patSize = pat.size();
    int n = s.size();
    if(patSize > n) return {-1};
    vi ans;
    ll p = 7;

    ll pat_hash = poly_hash(pat, p, mod);
    ll prev_hash = 0;
    for(int i = 0, j = i+patSize; j <= n; i++, j++){
        ll hash = rollingHash(s, prev_hash, i, j, p, mod);
        if(hash == pat_hash and check(s, pat, i, j)){
            ans.push_back(i);
        }
        prev_hash = hash;
    }
    if(ans.size() == 0){
        return {-1};
    }
    return ans;
}

void solve() {
    string name = "sajidanissaid";
    string pat = "sa";

    for(auto &el : rabinKarp(name, pat)){
        cout << el << " ";
    }
    cout << "\n";
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