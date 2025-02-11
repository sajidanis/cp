#include <bits/stdc++.h>

using namespace std;

struct node {
    int sum, pref, suff, ans;
    node(int val){
        sum = val;
        pref = suff = ans = max(0, val);
    }
    node() {
        sum = pref = suff = ans = 0;
    }
};

node* combine(node *l, node *r){
    node* d = new node();
    d->sum = l->sum + r->sum;
    d->pref = max(l->pref , l->sum + r->pref);
    d->suff = max(r->suff, r->sum + l->suff);
    d->ans = max(max(l->ans, r->ans), l->suff + r->pref );
    return d;
}
void combine(node *c, node *l, node *r){
    c->sum = l->sum + r->sum;
    c->pref = max(l->pref , l->sum + r->pref);
    c->suff = max(r->suff, r->sum + l->suff);
    c->ans = max(max(l->ans, r->ans), l->suff + r->pref );
}

void reset(node *t, int val){
    t->sum = val;
    t->ans = t->pref = t->suff = max(0, val);
}


struct segtree {
    size_t size;
    vector<node *> arr;

    void init(int N){
        size = 1;
        while(size < N) size *= 2;
        arr.assign(2*size, nullptr);
    }

    void build(vector<int> &nums, int idx, int lx, int rx){
        if(rx-lx == 1){
            arr[idx] = new node(nums[lx]);
            return;
        }

        int m = (lx + rx) / 2;
        build(nums, 2*idx+1, lx, m);
        build(nums, 2*idx+2, m, rx);

        arr[idx] = combine(arr[2*idx+1] , arr[2*idx+2]);
    }

    void build(vector<int> &nums){
        build(nums, 0, 0, size);
    }

    void set(int i, int val, int idx, int lx, int rx){
        if(rx-lx == 1){
            reset(arr[idx], val);
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m){
            set(i, val, 2*idx+1, lx, m);
        } else {
            set(i, val, 2*idx+2, m, rx);
        }

        combine(arr[idx], arr[2*idx+1], arr[2*idx+2]);
    }

    void set(int i, int val){
        set(i, val, 0, 0, size);
    }

    node* find(int l, int r, int idx, int lx, int rx){
        if(l >= rx || r <= lx){
            return new node();
        }
        if(lx >= l and r >= rx ){
            return arr[idx];
        }

        int m = (lx+rx) / 2;

        auto t1 = find(l, r, 2*idx+1, lx, m);
        auto t2 = find(l, r, 2*idx+2, m, rx);
        
        return combine(t1, t2);
    }

    node * find(int l, int r){
        return find(l, r, 0, 0, size);
    }
};

int main(){
    // freopen("./input", "r", stdin);
    // freopen("./output", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);

    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }

    segtree st;
    st.init(n);
    st.build(nums);

    cout << st.find(0, n)->ans << "\n";

    while(m--){
        int i, v;
        cin >> i >> v;
        st.set(i, v);

        cout << st.find(0, n)->ans << "\n";
    }

    return 0;
}