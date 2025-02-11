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
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
}

struct TrieNode{
    TrieNode *left, *right;
    size_t count = 0;
};

void insert(TrieNode *root, int x){
    TrieNode *curr = root;
    for(int i = 31 ; i >= 0 ; i--) {
        int bit = (x >> i) & 1;
        curr->count++;
        if(bit){
            if(curr->right == NULL){
                curr->right = new TrieNode();
            }
            curr = curr->right;
        } else {
            if(curr->left == NULL){
                curr->left = new TrieNode();
            }
            curr = curr->left;
        }
    }
    curr->count++;
}

ll find_kth_smallest(TrieNode *root, int k, int level, int num){
    if(level < 0){
        return num;
    }
    if(root->count < k){
        return num;
    }

    if(root->left != NULL and root->left->count >= k){
        return find_kth_smallest(root->left, k, level-1, num);
    } 
    if(root->right != NULL){
        int new_k = root->left == NULL ? k : (k - root->left->count);
        return find_kth_smallest(root->right, new_k, level-1, num + (1<<level));
    }
}

ll find_kth_smallest(TrieNode *root, int k){
    return find_kth_smallest(root, k, 31, 0);
}

void solve() {
    TrieNode *root = new TrieNode();
    insert(root, 234);
    insert(root, 125);
    insert(root, 35);
    insert(root, 756);

    cout << find_kth_smallest(root, 3) << "\n";

    insert(root, 1);
    insert(root, 234);

    cout << find_kth_smallest(root, 1);

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