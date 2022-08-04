#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,p1,p2;
  cin >> n >> p1 >> p2;
  p1--; p2--;
  int r = 0;
  while (p1 != p2) {
    p1 /= 2;
    p2 /= 2;
    r++;
  }
  cout << r;
}