// Problem Link -> https://leetcode.com/problems/longest-palindromic-substring/description/
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

void solve() {
    string s;
    cin >> s;
    ll n = s.size();

    ll max_length = 1;
    ll x = 0;
    ll y = 0;

    vector<vi> dp(n, vi(n, 0));
    
    loop(i, 0, n){
        dp[i][i] = 1;
        if(i == n-1) break;
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            max_length = 2;
            x = i;
            y = i+1;
        }
    }

    loop_rev(i, n-3, -1){
        loop(j, i+2, n){
            if(s[i] == s[j] and dp[i+1][j-1]){
                dp[i][j] = 1;
                if(j-i+1 > max_length){
                    max_length = j - i + 1;
                    x = i;
                    y = j;
                }
            }
        }
    }

    cout << s.substr(x, y-x+1);
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