#include <bits/stdc++.h>    
using namespace std;
int d[1005][1005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) d[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % 10007;
        }
    }
    cout << d[n][k];
}