// Problem Link -> Max Xor pair
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

struct TrieNode {
    TrieNode *left;
    TrieNode *right;
};

void insert(ll n, TrieNode *head){
    TrieNode *curr = head;
    for(int i = 63; i >= 0 ; i--){
        int bit = (n >> i) & 1;
        if(bit == 0) {
            if(curr->left == NULL){
                curr->left = new TrieNode();
            }
            curr = curr->left;
        } else {
            if(curr->right == NULL){
                curr->right = new TrieNode();
            }
            curr = curr->right;
        }
    }
}

ll findMaxXor(TrieNode *head, ll n){
    ll currXor = 0;
    TrieNode *curr = head;
    for(int i = 63; i >= 0 ; i--){
        int bit = (n >> i) & 1;
        if(bit == 0){
            // WE DESIRE TO HAVE 1 so right child should be there
            if(curr->right != NULL){
                curr = curr->right;
                currXor += (1 << i);
            } else {
                curr = curr->left;
            }
        } else {
            // WE DESIRE TO HAVE 0 so left child should be there
            if(curr->left != NULL){
                curr = curr->left;
                currXor += (1 << i);
            } else {
                curr = curr->right;
            }
        }
    }
    return currXor;
}

void solve() {
    ll n;
    cin >> n;
    TrieNode *root = new TrieNode();
    ll result = INT_MIN;
    if(n > 0){
        int x;
        cin >> x;
        insert(x, root);
        n--;
    }
    while(n--){
        int x;
        cin >> x;
        result = max(result, findMaxXor(root, x));
        insert(x, root);
    }
    cout << result;
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