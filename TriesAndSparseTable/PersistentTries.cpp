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

#define BIT_SIZE 32

struct TrieNode {
    TrieNode *left = nullptr, *right = nullptr;
    size_t st_size = 0;
    bool isDeleted = false;

    // Default constructor
    TrieNode() = default;

    // Copy constructor for deep copying
    TrieNode(const TrieNode &other) {
        if (other.left) {
            left = other.left; // Shallow copy of left child
        }
        if (other.right) {
            right = other.right; // Shallow copy of left child
        }
        st_size = other.st_size;
        isDeleted = other.isDeleted;
    }
};

struct PersistentTries {
    vector<TrieNode*> versions;  // Store versions of the trie
    size_t ver_sz = 0;

    void insert(int x) {
        TrieNode* prev_version = (ver_sz == 0) ? 
                                 new TrieNode() : versions[ver_sz - 1];

        // Create a new root by copying the previous version (deep copy)
        TrieNode* root = new TrieNode(*prev_version);
        TrieNode* curr = root;
        TrieNode* prev = prev_version;

        // Traverse the bits of the integer and construct the trie accordingly
        for (int i = BIT_SIZE-1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            curr->st_size++;
            if (bit) {  // If the bit is 1, go to the right child
                if (prev && prev->right != nullptr) {
                    curr->right = new TrieNode(*prev->right); // Deep copy the right child
                } else {
                    curr->right = new TrieNode();  // Create new right child
                }
                curr = curr->right;
                prev = prev ? prev->right : nullptr;
            } else {  // If the bit is 0, go to the left child
                if (prev && prev->left != nullptr) {
                    curr->left = new TrieNode(*prev->left);  // Deep copy the left child
                } else {
                    curr->left = new TrieNode();  // Create new left child
                }
                curr = curr->left;
                prev = prev ? prev->left : nullptr;
            }
        }
        curr->st_size++;

        // Add this version to the Persistent Tries
        versions.push_back(root);
        ver_sz++;
    }

    ll maxXor(ll l, ll r, ll x){
        TrieNode *prev = l <= 1 ? nullptr : versions[l-2];
        TrieNode *curr = versions[r-1];

        ll ans = 0;

        for(int i = BIT_SIZE-1 ; i >= 0 ; i--){
            int bit = (x >> i) & 1;
            if(bit){
                // Means bit is 1 and we need to look for 0
                if(!prev || (prev && !prev->left)){
                    if(curr->left){
                        ans += (1 << i);
                        curr = curr->left;
                        prev = NULL;
                    } else {
                        curr = curr->right;
                        prev = prev ? prev->right : NULL;
                    }
                } else if(curr->left && curr->left->st_size - prev->left->st_size > 0){
                    ans += (1 << i);
                    curr = curr->left;
                    prev = prev->left;
                } else {
                    curr = curr->right;
                    prev = prev->right;
                    // ans += 1 << i;
                }
            } else {
                // Means bit is 0 and we need to look for 1
                if(!prev || (prev && !prev->right)){ // If there is no path for previous versions
                    if(curr->right){
                        ans += (1 << i);
                        curr = curr->right;
                        prev = NULL;
                    } else {
                        curr = curr->left;
                        prev = prev ? prev->left : NULL;
                    }
                } else if(curr->right && curr->right->st_size - prev->right->st_size > 0){ 
                    ans += (1 << i); 
                    curr = curr->right;
                    prev = prev->right;
                } else {
                    curr = curr->left;
                    prev = prev->left;
                }
            }
        }
        return ans;
    }

    void deleteLastKEntries(ll k){
        // We just need to delete the last k versions set the isDeleted variable to 1
        while(k--){
            versions.pop_back();
            ver_sz--;
        }
    }

    ll countNumbersLess(ll l, ll r, ll k){
        TrieNode *prev = l <= 1 ? nullptr : versions[l-2];
        TrieNode *curr = versions[r-1];

        ll ans = 0;
        int i;
        for(i = BIT_SIZE-1; i >= 0 ; i--){
            if(curr == nullptr) break;
            int bit = (k >> i) & 1;

            if(bit){
                if(!prev || (prev && !prev->left)){
                    ans += curr->left ? curr->left->st_size : 0;
                    curr = curr->right;
                } else if(curr->left){
                    ans += curr->left->st_size - prev->left->st_size;
                    curr = curr->right;
                    prev = prev->right;
                } else {
                    curr = curr->right;
                    prev = prev->right;
                }
            } else {
                curr = curr->left;
                prev = prev ? prev->left : nullptr;
            }
        }
        if(i == -1 and curr) ans++; 
        return ans;
    }

    ll kthSmallest(TrieNode *curr, TrieNode *prev, ll level, ll k, ll ans){
        if(level < 0){
            return ans;
        }
        if(prev && (curr->st_size - prev->st_size) < k){
            return ans;
        }
        if(!prev && curr->st_size < k){
            return ans;
        }

        if(!prev){
            if(curr->left and curr->left->st_size >= k){
                return kthSmallest(curr->left, prev, level-1, k, ans);
            } 
            if(curr->right){
                ans += (1 << level);
                ll new_k = curr->left ? k - curr->left->st_size : k;
                return kthSmallest(curr->right, prev, level-1, new_k, ans);
            }
        } else{
            if(prev->left){
                if(curr->left and curr->left->st_size - prev->left->st_size >= k){
                    return kthSmallest(curr->left, prev->left, level-1, k, ans);
                }
                if(curr->right){
                    ans += (1 << level);
                    ll new_k = curr->left ? k - (curr->left->st_size - prev->left->st_size) : k;
                    return kthSmallest(curr->right, prev->right, level-1, new_k, ans);
                }
            } else {
                if(curr->left and curr->left->st_size >= k){
                    return kthSmallest(curr->left, prev->left, level-1, k, ans);
                } 
                if(curr->right){
                    ans += (1 << level);
                    ll new_k = curr->left ? k - curr->left->st_size : k;
                    return kthSmallest(curr->right, prev->right, level-1, new_k, ans);
                }
            }
        }
    }

    ll kthSmallest(ll l, ll r, ll k){
        TrieNode *prev = l <= 1 ? nullptr : versions[l-2];
        TrieNode *curr = versions[r-1];

        return kthSmallest(curr, prev, BIT_SIZE - 1, k, 0 );
    }
};

void solve() {
    PersistentTries *trie = new PersistentTries();
    ll m;
    cin >> m;
    while(m--){
        ll l, r, x, q, k;
        cin >> q;
        switch(q){
            case 0: 
                cin >> x;
                trie->insert(x);
                break;
            case 1:
                cin >> l >> r >> x;
                cout << ((trie->maxXor(l, r, x)) ^ x) << "\n";
                break;
            case 2:
                cin >> k;
                trie->deleteLastKEntries(k);
                break;
            case 3:
                cin >> l >> r >> x;
                cout << trie->countNumbersLess(l, r, x) << "\n";
                break;
            case 4:
                cin >> l >> r >> k;
                cout << trie->kthSmallest(l, r, k) << "\n";
        }
    }
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