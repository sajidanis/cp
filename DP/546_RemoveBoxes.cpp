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

vector<pair<int, int>> groups;

int rem(int i, int j, int extras){
    if(i > j) return 0;
    int k = groups[i].second + extras;
    int ans = (k*k) + rem(i+1, j, 0);

    for(int t = i + 2; t <= j ; t++){
        if(groups[t].first == groups[i].first){
            ans = max(ans, rem(i+1, t-1, 0) + rem(t, j, extras + groups[i].second));
        }
    }
    return ans;
}

int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    
    pair<int, int> temp = {-1, 0};
    for(int i = 0 ; i < n; i++){
        if(boxes[i] == temp.first){
            temp.second++;
        } else {
            if(temp.first != -1)groups.push_back(temp);
            temp.first = boxes[i];
            temp.second = 1;
        }
    }
    groups.push_back(temp);

    return rem(0, groups.size() - 1, 0);
}

void solve() {
    vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    cout << removeBoxes(boxes);
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