#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int tc, n;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  cout << fixed;
  cout.precision(6);
  while(tc--) {
    cin >> n;
    vector<pair<int, int>> points(n);
    vector<bool> mask(n, 1);
    double ans = 5000000.0;
    for (int i = 0; i < n; i++) cin >> points[i].X >> points[i].Y;
    fill(mask.begin(), mask.begin() + n/2, 0);
    do {
      double distX = 0.0, distY = 0.0;
      for (int i = 0; i < n; i++) {
        if (mask[i]) {
          distX += points[i].X;
          distY += points[i].Y;
        }
        else {
          distX -= points[i].X;
          distY -= points[i].Y;
        }
      }
      ans = min(ans, sqrt(distX*distX + distY*distY));
    } while(next_permutation(mask.begin(), mask.end()));
    cout << ans <<'\n';
  }
}