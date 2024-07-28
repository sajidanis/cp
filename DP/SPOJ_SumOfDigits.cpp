// Problem Link -> https://www.spoj.com/problems/CPCRC1C/
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

ll pt[12];

ll f(ll x){
    if(x / 10 == 0) return ((x) * (x + 1)) / 2;
    string s = to_string(x);
    int d = s.size(); // 
    int first = x / pt[d-1];

    ll res = 0;

    ll sum = pt[d-2] * 45 * (d-1);
    loop(i, 0, first){
        res = res + (i * pt[d-1] + sum);
    }

    ll restOfNumber = x % pt[d-1];
    res += (first) * (1 + restOfNumber);

    res += f(restOfNumber);
    return res;
}

void solve() {
    ll a, b;
    pt[0] = 1;
    loop(i, 1, 13){
        pt[i] = pt[i-1] * 10;
    }
    while(1){
        cin >> a >> b;
        if(a == -1 and b == -1){
            break;
        }

        cout << f(b) - f(a-1) << "\n";
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