#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int n;
    cin >> n;

    float totalSum = 0;

    while(n--){
        int t, l;
        cin >> t >> l;
        l = max(l, A);

        totalSum = B + (ceil((float)(l - A) / C)) * D;

        if(t > 2200){
            totalSum = totalSum * 1.2;
        }

        cout << round(totalSum) << "\n";
    }
    return 0;
}