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

unordered_set<string> dp;

bool checkPalindrome(string s){
    if(dp.contains(s)) return true;
    if(s.size() <= 1){
        return true;
    }
    int n = s.size();
    if(s[0] == s[n-1]){
        bool ans = checkPalindrome(s.substr(1, n-2));
        if(ans){
            dp.insert(s);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

string longestPalindrome(string s) {
    int n = s.size();

    int ans = 0;
    string res;
    for(int i = 0 ; i < n ; i++){
        for(int j = i; j < n ; j++){
            if(checkPalindrome(s.substr(i, j - i + 1))){
                if(j - i + 1 > ans){
                    ans = j - i + 1;
                    res = s.substr(i, j-i+1);
                }
            }
            if(ans == n){
                return s;
            }
        }
    }
    return res;
}

void solve() {
    cout << longestPalindrome("cbbd");
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