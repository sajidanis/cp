// Problem Link -> https://codeforces.com/problemset/problem/1133/A
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

    string t1, t2;
    cin >> t1 >> t2;

    ll h1, m1, h2, m2;
    
    h1 = atoll(t1.substr(0, 2).c_str());
    m1 = atoll(t1.substr(3).c_str());

    h2 = atoll(t2.substr(0, 2).c_str());
    m2 = atoll(t2.substr(3).c_str()); 

    ll total_minutes = (h2-h1)*60 + (m2 - m1);

    ll elapsed = total_minutes / 2;

    ll minutes = (m1 + (elapsed % 60)) % 60;
    ll hours = (h1 + (elapsed / 60) + (m1 + (elapsed %60)) / 60);

    cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') <<  minutes << "\n";
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