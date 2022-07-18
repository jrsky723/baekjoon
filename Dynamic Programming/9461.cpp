#include <bits/stdc++.h>   
using namespace std;

long long p[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    p[0] = 0, p[1] = 1, p[2] = 1, p[3] = 1, p[4] = 2;
    for (int i = 5; i <= 100; i++) p[i] = p[i - 1] + p[i - 5];
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        cout << p[num] << '\n';
    }
}