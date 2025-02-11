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

vector<vector<int>> dp;

int f(int i, int x, int ans, int n, int max_or, vector<int> &arr){
    if(i >= n){
        return INT_MAX;
    }
    if(x == max_or){
        return ans;
    }

    int choose = f(i+1, x | arr[i], ans + 1, n, max_or, arr);
    int unchoose = f(i+1, x, ans, n, max_or, arr);

    return min(choose, unchoose);
}

int minSubset(vector<int> &arr, int maxOr){
    vector<vector<int>> dp(arr.size() + 1, vector<int>(maxOr + 1, INT_MAX));

    dp[0][0] =0;

    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = 0 ; j <= maxOr ; j++){
            
        }
    }

}


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int max_or = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        max_or |= arr[i];
    }

    dp.assign(n+1, vector<int>(max_or + 1, -1));

    cout << f(0, 0, 0, n, max_or, arr);

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