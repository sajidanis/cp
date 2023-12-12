#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int k;
    vector<vector<int>> sets(n);
    for(int i = 0 ; i < n ; i++){
        cin >> k;
        vector<int> arr(k);
        for(int j = 0 ; j < k ; j++){
            cin >> arr[j];
        }
        sets[i] = arr;
    }

    vector<int> min_intersections(n);

    for(int i = 0 ; i < n-1 ; i++){
        int min_inter = INT32_MAX;
        for(int j = i+1 ; j < n ; j++){
            vector<int> res;
            set_intersection(sets[i].begin(), sets[i].end(), sets[j].begin(), sets[j].end(), back_inserter(res));
            min_inter = min(min_inter, (int) res.size());
        }
        min_intersections[i] = min_inter;
    }

    for(int i = 0 ; i < n-1 ; i++){
        cout << min_intersections[i] << " ";
    }

    long ans = 0;
    
}

void file_io(){
    std::ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE

    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
  
#endif
}

int main(){
    file_io();
    long t;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
    return 0;
}
