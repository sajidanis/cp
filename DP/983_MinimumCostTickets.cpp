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

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n, 0);

    dp[0] = *min_element(costs.begin(), costs.end());

    for(int i = 1 ; i < n ; i++){
        int curr = days[i];
        dp[i] = dp[i-1] + costs[0];
        auto w = lower_bound(days.begin(), days.end(), days[i] - 6);
        auto m = lower_bound(days.begin(), days.end(), days[i] - 29);

        if(curr - *w >= 7) w++;
        if(curr - *m >= 30) m++;

        if(curr - *w < 7){
            int idx = w - days.begin();
            if(idx > 0)
                dp[i] = min(dp[i], costs[1] + dp[idx-1]);
            else
                dp[i] = min(dp[i], costs[1]);
        }

        if(curr - *m < 30){
            int idx = m - days.begin();
            if(idx > 0)
                dp[i] = min(dp[i], costs[2] + dp[idx-1]);
            else
                dp[i] = min(dp[i], costs[2]);
        }
    }

    return dp[n-1];
}

void solve() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2, 7, 15};
    cout << mincostTickets(arr, costs);
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