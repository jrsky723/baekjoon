#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        stack <pair<int, int>> s;
        long long ans = 0;
        for (int p = 0; p < n; p++) {
            int h;
            cin >> h;
            int pos = p;
            while(!s.empty() && s.top().X >= h) {
                long long area = 1LL*s.top().X * (p - s.top().Y);
                ans = area > ans ? area : ans;
                pos = s.top().Y;
                s.pop();
            }
            s.push({ h, pos });
        }
        while (!s.empty()) {
            long long area = 1LL * s.top().X * (n - s.top().Y);
            ans = area > ans ? area : ans;
            s.pop();
        }
        cout << ans<<'\n';
    }
}