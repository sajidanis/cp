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

vs helper(ll n, ll m){
    if(n == 0) return {""};
    if(n == 1) return {"0", "1", "8"};

    vs temp = helper(n-2, m);
    vs result;

    for(auto &s: temp){
        if(n != m) result.push_back("0" + s + "0");
        result.push_back("1" + s + "1");
        result.push_back("8" + s + "8");
        result.push_back("6" + s + "9");
        result.push_back("9" + s + "6");
    }

    return result;
}

vs stroboNumbers(ll n){
    return helper(n, n);

}

void solve() {
    ll n;
    cin >> n;

    for(auto &el : stroboNumbers(n)){
        cout << el << "\n";
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