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

bool isValid(string s, vector<int> &arr){
    vector<int> freq(26, 0);

    for(int i = 0 ; i < s.size(); i++){
        freq[s[i] - 'a']++;
        if(freq[s[i] - 'a'] > arr[s[i] - 'a']){
            return false;
        }
    }
    return true;
}

int partitions(int i, int k, string &s, vector<int> &arr){
    if(i >= s.size()){
        return 0;
    }
    
    if(k == 1 and isValid(s.substr(i), arr)){
        return 1;
    }

    if(dp[i][k] != -1){
        return dp[i][k];
    }

    int res = 0;
    for(int j = i+1; j < s.size(); j++){
        if(isValid(s.substr(i, j - i), arr)){
            res = ((res % mod) + (partitions(j, k-1, s, arr) % mod) % mod);
        }
    }
    return dp[i][k] = res;
}

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<int> arr(26, 0);
    
    for(int i = 0 ; i < 6; i++){
        cin >> arr[i];
    }

    int K;
    cin >> K;

    dp.assign(N+1, vector<int>(K+1, -1  ));

    cout << partitions(0, K, s, arr);

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