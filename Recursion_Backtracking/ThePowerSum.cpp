// Problem Link -> https://www.hackerrank.com/challenges/the-power-sum/problem
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

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(auto &el : v){
        os << el << "";
    }
    return os;
}
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

ll powerSum(ll X, ll N, ll cur){
    ll value = X - pow(cur, N);
    if(value == 0){
        return 1;
    }
    if(value < 0){
        return 0;
    }

    return powerSum(value, N, cur+1) + powerSum(X, N, cur+1);
    
}

void solve() {
    ll X, N;
    cin >> X >> N;
    
    ll val = powerSum(X, N, 1);
    cout << val;
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