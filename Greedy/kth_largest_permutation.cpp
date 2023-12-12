#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k; 
    unordered_map<int, int> mp;
    vector<int> vi(n);

    for(int i = 0 ; i < n ; i++){
        cin >> vi[i];
        mp[vi[i]] = i;
    }
    int j = 0;
    int c = n;
    while(k--){
        int max_index = mp[c];
        int t = vi[j];
        vi[j] = c;
        vi[max_index] = t;

        mp[c] = j;
        mp[t] = max_index;
        j++;
        c--;

    }
    for(auto &el: vi){
        cout << el << " ";

    }
    cout << "\n";
    return 0;
}