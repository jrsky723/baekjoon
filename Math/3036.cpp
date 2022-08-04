#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int gcd(int a, int b) { 
  if (b == 0) return a;
  else gcd(b, a % b);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> rad(n);
  vector<pair<int, int>> rot(n);
  for (int i = 0; i < n; i++) cin >> rad[i];
  rot[0] = {1, 1};
  for(int i = 1; i < n; i++) {
    rot[i].X = rot[i - 1].X  * rad[i - 1];
    rot[i].Y = rot[i - 1].Y * rad[i];
    int GCD = gcd(rot[i].X, rot[i].Y);
    rot[i].X = rot[i].X / GCD;
    rot[i].Y = rot[i].Y / GCD;
    cout << rot[i].X << '/' << rot[i].Y << '\n';
  }
}