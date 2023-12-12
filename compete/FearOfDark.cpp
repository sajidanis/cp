#include <bits/stdc++.h>

using namespace std;

double calcDist(int ax, int ay, int bx, int by){
    return sqrtf((bx - ax) * (bx-ax) + (by-ay) * (by - ay));
}

bool checkAns(int ax, int ay, int bx, int by, int px, int py, double ans){
    double distA_B = calcDist(ax, ay, bx, by);
    double distA_P = calcDist(ax, ay, px, py);
    double distB_P = calcDist(bx, by, px, py);
    double distA_O = calcDist(ax, ay, 0, 0);
    double distB_O = calcDist(bx, by, 0, 0);

    if(distA_P <= ans && distA_O <= ans){
        return true;
    }

    if(distB_P <= ans && distB_O <= ans){
        return true;
    }

    if(distA_P <= ans && distB_O <= ans && distA_B <= 2*ans){
        return true;
    }

    if(distB_P <= ans && distA_O <= ans && distA_B <= 2*ans){
        return true;
    }

    return false;
}

void solve(){
    int px, py, ax, ay, bx, by;
    double ans = -1;
    cin >> px >> py >> ax >> ay >> bx >> by;

    double min_space = 0;
    double max_space = 10000;
    int iteration_count = 2000;
    double eps = 1e-6;

    for(int i = 0 ; i < iteration_count && min_space + eps < max_space ; i++){
        double mid = 0.5 * (min_space + max_space);
        if(checkAns(ax, ay, bx, by, px, py, mid)){
            ans = mid;
            max_space = mid;
        } else {
            min_space = mid;
        }
    }
    cout << std::setprecision(12) << ans;
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

    long t = 0;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
}