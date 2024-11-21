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

set<int> find1100(string &s){
    ll l = 0, r = 3;
    set<int> ans;
    while(r < s.size()){
        if(s[l] == '1' and s[l+1] == '1' and s[l+2] == '0' and s[l+3] == '0'){
            ans.insert(l);
        }
        l++; r ++;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    set<int> ans = find1100(s);
    ll q;
    cin >> q;
    vector<pair<ll, ll>> op(q);
    loop(i, 0, q){
        int x,y;
        cin >> x >> y;
        x--;

        if(s[x] - '0' == y){
            cout << ((ans.size() > 0) ? "YES\n" : "NO\n");
            continue;
        }

        for (int j = max(0, x - 3); j <= x; ++j) {
            if (j + 3 < s.size() && s.substr(j, 4) == "1100") {
                ans.erase(j);
            }
        }

        s[x] = '0' + y;

        for (int j = max(0, x - 3); j <= x; ++j) {
            if (j + 3 < s.size() && s.substr(j, 4) == "1100") {
                ans.insert(j);
            }
        }
        cout << ((ans.size() > 0) ? "YES\n" : "NO\n");
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    cin >> t;
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