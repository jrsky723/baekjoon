#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (1) {
        int l, p, v;
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) break;
        int ans = l * (v / p);
        if (v % p > l) ans += l;
        else ans += v % p;
        cout << "Case " << t++ <<": "<< ans <<'\n';
    }
}