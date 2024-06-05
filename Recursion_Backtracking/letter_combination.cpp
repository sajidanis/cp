// Problem Link -> https://leetcode.com/problems/letter-combinations-of-a-phone-number/
/* Md Sajid Anis */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 			 long long int
#define ld 			 long double
#define mod             1000000007
#define inf             1e18
#define endl 			 "\n"
#define pb 			 emplace_back
#define vi              vector<ll>
#define vs 			 vector<string>
#define pii             pair<ll,ll>
#define ump 			 unordered_map
#define mp 			 map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 			 first
#define ss 			 second
#define loop(var, start, end) for(ll var = start; var < end; var++)
#define loop_rev(var, start, end) for(ll var = start; var > end; var--)

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
    freopen("./output", "w", stdout);
#endif
}

vs util(string s, map<string, vs> &charMap){
    if(s.length() == 1){
        return charMap[s];
    }

    auto prev = util(s.substr(1), charMap);

    // Self Work
    auto cur = charMap[s.substr(0,1)];
    vs res;
    for(auto &el : cur){
        for(auto &d : prev){
            res.push_back(el + d);
        }
    }
    return res;
}

void solve() {
    map<string, vs> charMap;
    charMap["2"] = {"a", "b", "c"};
    charMap["3"] = {"d", "e", "f"};
    charMap["4"] = {"g", "h", "i"};
    charMap["5"] = {"j", "k", "l"};
    charMap["6"] = {"m", "n", "o"};
    charMap["7"] = {"p", "q", "r", "s"};
    charMap["8"] = {"t", "u", "v"};
    charMap["9"] = {"w", "x", "y", "z"};

    string s;
    cin >> s;
    auto res = util(s, charMap);
    for(auto &el : res){
        cout << el << " ";
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    // cin >> t;
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