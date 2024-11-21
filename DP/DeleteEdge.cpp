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

int getSubtreeSum(int root, int par, vector<list<int>> &graph, vector<int> &dp, vector<int> &A){
    if(graph[root].size() == 1){
        return dp[root] = A[root-1];
    }
    
    if(dp[root] != -1) return dp[root];
    
    int total_sum = A[root-1];
    
    for(auto &nbr : graph[root]){
        if(nbr == par) continue;
        total_sum += getSubtreeSum(nbr, root, graph, dp, A);
    }
    
    return dp[root] = total_sum;
}

int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    long long total_sum = 0;
    for(auto &el : A) total_sum += el;
    
    long long S = total_sum / 2;
    
    vector<list<int>> graph(A.size() + 1, list<int>());
    vector<int> dp(A.size() + 1, -1);
    for(auto &el : B){
        graph[el[0]].push_back(el[1]);
        graph[el[1]].push_back(el[0]);
    }
    
    getSubtreeSum(1, -1, graph, dp, A);
    
    long long bestFound = INT_MAX;
    long long X = 0;
    for(int i = 1 ; i < dp.size() ; i++){
        if(abs(S - dp[i]) < bestFound){
            X = dp[i];
            bestFound = abs(S - dp[i]);
        }
    }
    
    return (X * (total_sum - X)) % (1000000007);
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<int> A(n);
    loop(i, 0, n){
        cin >> A[i];
    }

    vector<vector<int>> B(m, vector<int>(2));

    loop(i, 0, m){
        cin >> B[i][0] >> B[i][1];
    }

    cout << deleteEdge(A, B);
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