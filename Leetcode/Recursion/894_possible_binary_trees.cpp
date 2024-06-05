// Problem Link -> https://leetcode.com/problems/all-possible-full-binary-trees/description/
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

typedef struct Node{
    Node *left;
    Node *right;
    ll val;

    Node() : left(nullptr), right(nullptr), val(0) {}
} Node;

vector<Node *> printFBT(ll n, ump<int, vector<Node *>> &memo){
    if(n == 1){
        return { new Node() };
    }

    vector<Node *> res;
    for(int i = n-2 ; i > 0 ; i-=2){
        if(memo.find(i) == memo.end()){
            memo[i] = printFBT(i, memo);
        }
        if(memo.find(n-i-1) == memo.end()){
            memo[i] = printFBT(i, memo);
        }
        auto left_trees = printFBT(i, memo);
        auto right_trees = printFBT(n-1-i, memo);
        for(int j = 0; j < left_trees.size() ; j++){
            for(int k = 0 ; k < right_trees.size() ; k++){
                Node *head = new Node();
                head->left = left_trees[j];
                head->right = right_trees[k];
                res.push_back(head);
            }
        }
    }
    return res;
}


void solve() {
    ll n;
    cin >> n;
    ump<int, vector<Node *>> memo;
    auto res = printFBT(n, memo);
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