#include <bits/stdc++.h>

using namespace std;

struct segtree {
    size_t size;
    vector<int> arr;

    void init(int N){
        size = 1;
        while(size < N) size *= 2;
        arr.assign(2*size, -1);
    }

    void build(vector<int> &nums, int idx, int lx, int rx){
        if(rx-lx == 1){
            if(nums[lx] == 1){
                arr[idx] = 1;
            } else {
                arr[idx] = 0;
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(nums, 2*idx+1, lx, m);
        build(nums, 2*idx+2, m, rx);

        arr[idx] = arr[2*idx+1] + arr[2*idx+2];
    }

    void build(vector<int> &nums){
        build(nums, 0, 0, size);
    }

    void set(int i, int idx, int lx, int rx){
        if(rx-lx == 1){
            if(arr[idx] == 0){
                arr[idx] = 1;
            } else {
                arr[idx] = 0;
            }
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m){
            set(i, 2*idx+1, lx, m);
        } else {
            set(i, 2*idx+2, m, rx);
        }

        arr[idx] = arr[2*idx+1] + arr[2*idx+2];
    }

    void set(int i){
        set(i, 0, 0, size);
    }

    int find(int l, int r, int idx, int lx, int rx){
        if(l >= rx || r <= lx){
            return 0;
        }
        if(lx >= l and r >= rx ){
            return arr[idx];
        }

        int m = (lx+rx) / 2;

        auto t1 = find(l, r, 2*idx+1, lx, m);
        auto t2 = find(l, r, 2*idx+2, m, rx);

        return t1+t2;
    }

    int find(int l, int r){
        return find(l, r, 0, 0, size);
    }

    int find_k(int k, int idx, int lx, int rx){
        if(k > arr[idx]){
            return -1;
        }

        if(rx-lx == 1){
            return lx;
        }

        int m = (lx+rx)/ 2;

        if(k <= arr[2*idx+1] ){
            return find_k(k, 2*idx+1, lx, m);
        } else {
            return find_k(k - arr[2*idx+1], 2*idx+2, m, rx);
        }
    }

    int find_k(int k){
        return find_k(k, 0, 0, size);
    }
};

int main(){
    // freopen("./input", "r", stdin);
    // freopen("./output", "w", stdout);

    int N, Q;
    cin >> N >> Q;
    vector<int> nums(N);
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
    }

    segtree st;

    st.init(N);
    st.build(nums);

    while(Q--){
        int op, val;
        cin >> op >> val;
        if(op == 1){
            st.set(val);
        } else{
            cout << st.find_k(val+1) << "\n";
        }
    }

    // cout << st.find_k(2) << "\n";
    // cout << st.find(0, 4) << "\n";


    return 0;
}