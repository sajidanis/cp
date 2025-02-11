/**
 * @file reverse_an_array.cpp
 * @author your name (you@domain.com)
 * @brief  Reverse an array recursively
 * @version 0.1
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// Problem Link ->
/* Md Sajid Anis */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 			 long long int
#define ld 			 long double
#define mod             1000000007
#define inf             1e18
#define endl 			 "\n"
#define pb 			 emplace_back
#define vi              vector<ll>
#define vs 			 vector<string>
#define pii             pair<ll,ll>
#define ump 			 unordered_map
#define mp 			 map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 			 first
#define ss 			 second
#define loop(var, start, end) for(ll var = start; var < end; var++)
#define loop_rev(var, start, end) for(ll var = start; var > end; var--)

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
    freopen("./output", "w", stdout);
#endif
}

void reverse_arr(ll i, ll n, vi &arr){
    if(i == n - 1){
        arr[n - i - 1] = arr[i];
        return;
    }
    ll k = arr[i];
    reverse_arr(i+1, n, arr);
    arr[n-i-1] = k;
}

void solve() {
    ll n;
    cin >> n;

    vi arr(n);
    loop(i, 0, n){
        cin >> arr[i];
    }

    reverse_arr(0, n, arr);

    for(auto &el : arr){
        cout << el << " ";
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    // cin >> t;
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