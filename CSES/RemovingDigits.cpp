// Problem Link -> https://cses.fi/problemset/task/1637
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

vi getDigits(ll n){
    vi digits;
    while(n > 0){
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

ll getMinSteps(ll n, int *dp){
    if(n == 0){
        return 0;
    }
    if(n < 0 ) return 1e9;
    if(dp[n] != -1) return dp[n];
    
    vi digits = getDigits(n);

    ll ans = 1e9;

    for(auto &d: digits){
        if(d == 0) continue;
        ans = min(ans, getMinSteps(n - d, dp) + 1);
    }

    return dp[n] = ans;
}


void solve() {
    ll n;
    cin >> n;
    int dp[n+1];
    memset(dp, -1, sizeof dp);
    cout << getMinSteps(n, dp);
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