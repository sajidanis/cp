// Problem Link -> https://codeforces.com/problemset/problem/1199/A
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

vi compute_left_min(const vi &arr, ll x){
    deque<ll> dq;
    ll n = arr.size();
    vi min_array(n, INT64_MAX);

    for(ll i = 0 ; i < n ; i++){
        while(!dq.empty() and dq.front() < i - x){
            dq.pop_front();
        }

        // now i will check if my current element is minimum that front of deque or not
        while(!dq.empty() and arr[dq.back()] >= arr[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        if(i > 0){
            min_array[i] = arr[dq.front()];
        }
    }
    return min_array;
}

vi compute_right_min(const vi &arr, ll y){
    deque<ll> dq;
    ll n = arr.size();

    vi min_array(n, INT64_MAX);

    for(ll i = n-1 ; i >= 0 ; i--){
        while(!dq.empty() and dq.front() > i + y){
            dq.pop_front();
        }

        while(!dq.empty() and arr[dq.back()] >= arr[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        if(i < n-1) {
            min_array[i] = arr[dq.front()];
        }
    }
    return min_array;
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    vi arr(n);
    loop(i, 0, n) {
        cin >> arr[i];
    }


    /**
     * @brief 
     * This piece of code is using the deque monotonic sequence to precompute the minimum of 
     * all the indices 
     * 
     */

    vi left_min = compute_left_min(arr, x);
    vi right_min = compute_right_min(arr, y);

    loop(i, 0, n){
        if(left_min[i] >= arr[i] and right_min[i] >= arr[i]){
            cout << i + 1;
            return;
        } 
    }



    /**
     * @brief 
     * This below code is the brute force solution
     * 
     */
    // bool flag = false;

    // loop(i, 0, n){
    //     flag = false;
    
    //     loop_rev(prev, i-1, i-x-1){
    //         if(prev < 0) break;

    //         if(arr[prev] < arr[i]){
    //             flag = true;
    //             break;
    //         }
    //     }

    //     loop(next, i+1, i+y+1){
    //         if(next >= n) break;

    //         if(arr[next] < arr[i]){
    //             flag = true;
    //             break;
    //         }
    //     }

    //     if(flag) continue;
    //     cout << i+1;
    //     break;
    // }
    // return;
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