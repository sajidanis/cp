// Problem Link -> https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/
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

int numberOfArithematicSlices(vector<int> &a){
    int n = a.size();
    if(n == 1) return 0;
    vector<unordered_map<int, int>> dp(n);

    int diff = a[1] - a[0];
    dp[1][diff] = 1;

    int ans = 0;
    for(int i = 2; i < n ; i++){
        for(int j = i-1 ; j >= 0 ; j--){
            diff = a[i] - a[j];
            if(dp[j].count(diff)){
                dp[i][diff] += dp[j][diff] + 1;
                ans += dp[j][diff];
            } else {
                dp[i][diff] += 1;
            }
        }
    }

}

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