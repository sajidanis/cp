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
#define pb              push_back
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
    freopen("/home/sajid/Documents/cp/input", "r", stdin);
    freopen("/home/sajid/Documents/cp/output", "w", stdout);
#endif
}

vector<string_view> split(string_view s, string_view delim) {
    vector<string_view> tokens;
    size_t start = 0;
    size_t dlen = delim.size();

    if (dlen == 0) {  // edge case: empty delimiter
        tokens.emplace_back(s);
        return tokens;
    }

    while (true) {
        size_t pos = s.find(delim, start);
        if (pos == string_view::npos) {
            tokens.emplace_back(s.substr(start));
            break;
        }
        tokens.emplace_back(s.substr(start, pos - start));
        start = pos + dlen;
    }
    return tokens;
}

void solve() {
    string s;
    cin >> s;

    vector<string_view> parts = split(s, "+");
    vi nums;

    for(auto &el : parts){
        nums.push_back(stoi(string(el)));
    }

    sort(nums.begin(), nums.end());

    loop(i, 0, nums.size()){
        cout << nums[i];
        if(i != nums.size() - 1){
            cout << "+";
        }
    }
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