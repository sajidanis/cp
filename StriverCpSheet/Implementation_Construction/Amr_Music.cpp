// Problem Link -> https://codeforces.com/problemset/problem/507/A
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
#define pb              push_back
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
    freopen("/home/sajid/Documents/cp/input", "r", stdin);
    freopen("/home/sajid/Documents/cp/output", "w", stdout);
#endif
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> days_required(n);

    loop(i, 0, n) {
        cin >> days_required[i].first;
        days_required[i].second = i+1; // index starts from 1 
    }

    sort(days_required.begin(), days_required.end());

    vi arr;
    loop(i, 0, n){
        if(days_required[i].first <= k){
            arr.pb(days_required[i].second);
            k -= days_required[i].first;
        } else {
            break;
        }
    }

    cout << arr.size() << "\n";
    for(auto &el : arr){
        cout << el << " ";
    }
    return;
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