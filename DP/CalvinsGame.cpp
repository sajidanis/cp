// Problem Link -> https://www.codechef.com/INOIPRAC/problems/INOI1301
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

// void maxScoreForward(ll k, ll n, vi &arr, vi &dp){
//     dp[k] = 0;
//     if(k + 1 < n){
//         dp[k+1] = max(dp[k], dp[k+1] + arr[k+1]);
//     }
//     loop(j, k+2, n){
//         dp[j] = max(dp[j-2], dp[j-1]) + arr[j];
//     } 
// }

// void maxScoreBackward(ll n, vi &arr, vi &dp){

//     dp[n-2] = dp[n-1] + arr[n-2];

//     loop_rev(i, n-3, -1){
//         dp[i] = max(dp[i+2], dp[i+1]) + arr[i];
//     }
// }




void solve() {
    ll N, k;
    cin >> N >> k;
    vi arr(N+1);
    loop(i, 1, N+1){
        cin >> arr[i];
    }

    vi front(N+1, 0);
    vi back(N+1, 0);

    front[k+1] = arr[k+1];

    loop(i, k+2, N+1){  
        front[i] = max(front[i-1], front[i-2]) + arr[i];
    }

    back[1] = arr[1];
    back[2] = arr[1] + arr[2];

    loop(i, 3, N+1){
        back[i] = max(back[i-1], back[i-2]) + arr[i];
    }

    ll res = -inf;

    loop(i, k, N+1){
        res = max(res, front[i] + back[i] - arr[i] );
    }

    cout << res;
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