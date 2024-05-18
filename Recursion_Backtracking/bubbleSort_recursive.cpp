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

bool bubbleSortUtil(ll i, ll j, ll n, vi &arr, bool flag){
    bool fl = flag;
    if(i > n - 2){
        return flag;
    }
    if(arr[i] > arr[j]){
        swap(arr[i], arr[j]);
        fl = true;
    }
    return bubbleSortUtil(i+1, j+1, n, arr, fl);
}

void bubbleSort(ll n, vi &arr){
    if(!bubbleSortUtil(0, 1, n, arr, false)){
        return;
    }
    bubbleSort(n, arr);
}

void solve() {
    ll n;
    cin >> n;
    vi arr(n);
    loop(i, 0, n){
        cin >> arr[i];
    }

    bubbleSort(n, arr);

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