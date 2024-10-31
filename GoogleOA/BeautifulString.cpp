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

vector<vector<bool>> dp;

string smallestBeautifulString(string s, int k) {
    int n = (int) s.size();
    int pos = -1;
    
    for (int i = n - 1; i >= 0 && pos < 0; i--) {
        int cur = s[i] - 'a';
        cur++;
        while (cur < k && pos < 0) {
            bool isPal = false;
            if (i - 1 >= 0 && (s[i - 1] - 'a') == cur) isPal = true;
            if (i - 2 >= 0 && (s[i - 2] - 'a') == cur) isPal = true;
            if (!isPal) {
                s[i] = (char) (cur + 'a');
                pos = i;
            }
            cur++;
        }
    }
    
    if (pos < 0) return "-1";
    
    for (int i = pos + 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            bool isPal = false;
            if (i - 1 >= 0 && (s[i - 1] - 'a') == j) isPal = true;
            if (i - 2 >= 0 && (s[i - 2] - 'a') == j) isPal = true;
            if (!isPal) {
                s[i] = (char) (j + 'a');
                break;
            }
        }
    }
    
    return s;
}

void solve() {
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    dp.assign(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++){
        dp[i][i] = true;
        if(i + 1 < N and s[i] == s[i+1]){
            dp[i][i+1] = true;
        }
    }
    
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