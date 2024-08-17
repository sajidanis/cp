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
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
}

ll perfectSum(int *arr, int n, int sum, int i){
    if(sum == 0){
        return 1;
    }
    
    if(i < 0 || sum < 0){
        return 0;
    }

    auto t1 = perfectSum(arr, n, sum, i-1);
    auto t2 = perfectSum(arr, n, sum-arr[i], i-1);
    
    return t1+t2;
}

int perfectSum(int arr[], int n, int sum) {
    // Your code goes here
    vector< vector <int> > dp(n+1, vector<int>(sum+1, 0));
    
    dp[0][0] = 1;
    
    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 0; j < sum+1 ; j++){
            dp[i][j] = dp[i-1][j];
            if(j - arr[i] >= 0){
                dp[i][j] += dp[i-1][j-arr[i]];
            }
        }
    }
    return dp[n][sum];
    
}

void solve() {
    int n, sum;

    cin >> n >> sum;

    int a[n];
    a[0] = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << perfectSum(a, n, sum, n);

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