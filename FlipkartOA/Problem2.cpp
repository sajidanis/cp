// Problem Link -> https://www.desiqna.in/17550/flipkart-sde-coding-oa-questions-and-solutions-set-25
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

struct TreeNode{
    TreeNode *left = nullptr, *right = nullptr;
    int val;
};

void inorder(TreeNode *root, vector<int> &res){
    if(root == NULL){
        return;
    }

    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

void solve() {
    ll n;
    cin >> n;
    vector<int> pop(n, 0);
    loop(i, 0, n){
        cin >> pop[i];
    }

    int edges, children;
    cin >> edges >> children;


    vector<TreeNode *> nodes(n, nullptr);

    for(int i = 0 ; i < n-1 ; i++){
        int u, v;
        cin >> u >> v;
        if(nodes[u] == nullptr){
            nodes[u] = new TreeNode();
            nodes[u]->val = u;
        }

        if(nodes[v] == nullptr){
            nodes[v] = new TreeNode();
            nodes[v]->val = v;
        }
     
        if(nodes[u]->left){
            nodes[u]->right = nodes[v];
        } else {
            nodes[u]->left = nodes[v];
        }
    }

    int m;
    cin >> m;
    
    vector<int> res;
    inorder(nodes[0], res);

    cout << pop[res[m-1]];

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