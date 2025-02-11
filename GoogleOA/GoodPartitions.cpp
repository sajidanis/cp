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

bool canDivide(const vector<int> &A, int K, int X){
    int n = A.size();
    int cnt = 1;
    multiset<int> s;
    s.insert(A[0]);


    for(int i = 1; i < n ; i++){
        int curr = A[i], diff = INT_MAX;
        auto it = s.lower_bound(curr);
        if(it != s.end()) diff = min(diff, abs(curr - *it));
        if(it != s.begin()) diff = min(diff, abs(curr - *prev(it)));

        if(diff >= X) s.insert(curr);
        else{
            cnt++;
            s.clear();
            s.insert(curr);
        }
    }

    return cnt <= K;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }

    int l = 0;
    int r = 1e9;
    int res = 0;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(canDivide(arr, k, m)){
            res = m;
            l = m + 1;
        } else {
            r = m -1;
        }
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