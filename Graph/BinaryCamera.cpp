// Problem Link -> https://leetcode.com/problems/binary-tree-cameras/description/
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int f(TreeNode *root, bool cam, bool pcam){
    if(root != NULL and root->left == NULL and root->right == NULL){
        if(!pcam){
            return 1;
        } else {
            return 0;
        }
    }
    int ans = 0;
    if(cam){
        ans = 1;
        if(root->left != NULL){
            ans += min(f(root->left, 0, 1), f(root->left, 1, 1));
        }
        if(root->right != NULL){
            ans += min(f(root->right, 0, 1), f(root->right, 1, 1));
        }

    } else if(!cam and pcam){
        if(root->left != NULL){
            ans += min(f(root->left, 0, 0), f(root->left, 1, 0));
        }
        if(root->right != NULL){
            ans += min(f(root->right, 0, 0), f(root->right, 1, 0));
        }
        
    } else if(!cam and !pcam){
        if(root->left != NULL and root->right != NULL){
            int way1 = f(root->left, 1, 0) + min(f(root->right, 0, 0), f(root->right, 1, 0));
            int way2 = f(root->right, 1, 0) + min(f(root->left, 0, 0), f(root->left, 1, 0));
            ans = min(way1, way2);
        } else if(root->left == NULL){
            ans = f(root->right, 1, 0);
        } else if(root->right == NULL){
            ans = f(root->left, 1, 0);
        }
    }
    return ans;
}

void solve() {
    TreeNode *root = new TreeNode();
    root->left = new TreeNode();
    root->left->left = new TreeNode();
    root->left->left->left = new TreeNode();
    root->left->left->left->right = new TreeNode();

    cout << min(f(root, 0, 0), f(root, 0, 0));
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