// Problem Link -> https://atcoder.jp/contests/dp/tasks/dp_e
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

ll modified_knapsack(ll W, ll N, vi &wt, vi &val){
    vi dp1(N * 1000 + 1, inf);
    vi dp2(N * 1000 + 1, inf);

    dp1[0] = 0;
    dp1[val[0]] = wt[0];

    loop(i, 1, N+1){
        loop(j, 0, N * 1000 + 1){
            dp2[j] = dp1[j];
            if(val[i] <= j){
                dp2[j] = min(dp1[j], dp1[j-val[i]] + wt[i]);
            }
        }
        dp2.swap(dp1);
        dp2.clear();
    }

    ll res = 0;
    loop(i, 0, N * 1000 + 1){
        if(dp1[i] <= W){
            res = i;
        }
    }
    return res;
}

void solve() {
    ll N, W;
    cin >> N >> W;

    vi wt(N+1, 0);
    vi val(N+1, 0);
    ll su = 0;
    loop(i, 1, N+1){
        cin >> wt[i] >> val[i];
        su += val[i];
    }

    cout << modified_knapsack(W, N, wt, val);

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