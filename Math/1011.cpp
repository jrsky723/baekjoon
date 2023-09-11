#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int d = y - x;
        int dwsq = sqrt(d);
        int upsq = dwsq + 1;
        int dw = dwsq * dwsq;
        int up = upsq * upsq;
        int ans = 0;
        int dist = up - dw - 1;
        if (d > dw + dist/2) {
            ans = upsq * 2 - 1;
        }
        else if (d > dw){
            ans = dwsq * 2;
        }
        else {
            ans = dwsq * 2 - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}