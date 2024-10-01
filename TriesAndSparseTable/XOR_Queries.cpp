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

const int n = 500005 * 22;

struct node {
    int left, right, count;
};

node trie[n];
int root[n];

int new_ptr;

int insert(int prev, int x){
    int temp = new_ptr++;
    int curr = temp;
    trie[curr] = trie[prev];
    for(int i = 20; i >= 0 ;i--){
        int b = (x >> i) & 1;
        if(b){
            trie[curr].right = new_ptr++;
            trie[trie[curr].right] = trie[trie[prev].right];
            trie[trie[curr].right].count++;
            curr = trie[curr].right;
            prev = trie[prev].right;
        } else {
            trie[curr].left = new_ptr++;
            trie[trie[curr].left] = trie[trie[prev].left];
            trie[trie[curr].left].count++;
            curr = trie[curr].left;
            prev = trie[prev].left;
        }
    }
    return temp;
}

int maxXor(int prev, int curr, int x){
    int y = 0;

    for(int i = 20 ; i >= 0 ; i--){
        int b = (x >> i) & 1;
        if(b){
            if(trie[trie[curr].left].count > trie[trie[prev].left].count){
                curr = trie[curr].left;
                prev = trie[prev].left;
                
            } else {
                curr = trie[curr].right;
                prev = trie[prev].right;
                y += (1 << i) ;
            }
        } else {
            if(trie[trie[curr].right].count > trie[trie[prev].right].count){
                curr = trie[curr].right;
                prev = trie[prev].right;
                y += (1 << i) ;
            } else {
                curr = trie[curr].left;
                prev = trie[prev].left;
            }
        }
    }
    return y;

}

int lessThankX(int prev, int curr, int x){
    int ans = 0 ;

    for(int i = 20; i >= 0 ; i--){
        int b = (x >> i) & 1;
        if(b){
            ans += trie[trie[curr].left].count - trie[trie[prev].left].count;
            curr = trie[curr].right;
            prev = trie[prev].right;
        } else {
            curr = trie[curr].left;
            prev = trie[prev].left;
        }
    }
    ans += trie[curr].count - trie[prev].count;
    return ans;
}


int kthSmallest(int prev, int curr, int k){
    int ans = 0;
    for(int i = 20 ; i >= 0 ; i--){
        // int b = (x >> i) & 1;
        if(trie[trie[curr].left].count - trie[trie[prev].left].count >= k){
            curr = trie[curr].left;
            prev = trie[prev].left;
        } else {
            k -= trie[trie[curr].left].count - trie[trie[prev].left].count;
            curr = trie[curr].right;
            prev = trie[prev].right;
            ans += (1 << i);
        }
    }
    return ans;
}


void solve() {
    
    root[0] = 0;
    trie[0].left = trie[0].right = trie[0].count = 0;
    
    int m;
    int n = 1;
    cin >> m;

    new_ptr = 1;

    while(m--){
        int type;
        cin >> type;
        if(type == 0){
            // insert
            int x;
            cin >> x;
            root[n] = insert(root[n-1], x);
            n += 1;

        } else if(type == 1){
            int l, r, x;
            cin >> l >> r >> x;
            cout << maxXor(root[l-1], root[r], x) << "\n";

        } else if(type == 2){
            int k;
            cin >> k;
            n -= k;

        } else if(type == 3){
            int l, r, x;
            cin >> l >> r >> x;
            cout << lessThankX(root[l-1], root[r], x) << "\n";
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << kthSmallest(root[l-1], root[r], k) << "\n";
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