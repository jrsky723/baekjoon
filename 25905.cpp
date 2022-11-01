#include <bits/stdc++.h>
using namespace std;

double p[10];
double ans = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 10; ++i) cin >> p[i];

  vector<int> mask;
  for (int i = 0; i < 10; ++i) mask.push_back(i);
  do {
    double mx = 1;
    for (double i = 1; i < 10; i += 1.0) mx *= p[mask[i]] / i * 10;
    ans = max(ans, mx);
  } while(next_permutation(mask.begin(), mask.end()));
  cout.precision(7);
  cout.fixed;
  cout << ans;
}