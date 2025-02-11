// Problem Link -> https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
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
int minSquares(int i, int sum, vector<int> &squares){
    if(i >= squares.size() || sum < 0){
        return INT_MAX;
    }
    if(sum == 0){
        return 0;
    }

    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    
    int choose = minSquares(i, sum - squares[i], squares);
    if(choose != INT_MAX){
        choose += 1;
    }   
    int unchoose = minSquares(i+1, sum, squares);
    
    return dp[i][sum] = min(choose, unchoose);
}

int MinSquares(int n) {
    // Code here
    vector<int> available;
    
    for(int i = 1 ; i*i <= n ; i++){
        available.push_back(i*i);
    }
    
    int m = available.size();
    
    dp.assign(m, vector<int>(n+1, -1));
    
    int res = minSquares(0, n, available);
    return res;
    
}

void solve() {
    cout << MinSquares(100);
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