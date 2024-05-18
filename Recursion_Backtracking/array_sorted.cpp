/**
 * @file array_sorted.cpp
 * @author your name (you@domain.com)
 * @brief Check if a given array is sorted or not using recursion
 * @version 0.1
 * @date 2024-05-18
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

bool util(ll i, ll j, ll n, vi &arr){

    if(i >= n-1 ) return true;
    if(arr[i] > arr[j]) return false;
    
    bool ans = util(i+1, j+1, n, arr);

    if(!ans){
        return false;
    } 
    return true;
}

bool isSorted(ll i, ll n, vi &arr){
    if(n - i - 1 == 0) return true;

    bool ans = isSorted(i+1, n, arr);

    return ans and (arr[i] <= arr[i+1]);
}

void solve() {

    ll n;
    cin >> n;
    vi arr(n);
    loop(i, 0, n){
        cin >> arr[i];
    }

    // cout << util(0, 1, n, arr);
    cout << isSorted(0, n, arr);

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