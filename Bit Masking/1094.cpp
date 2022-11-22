#include <bits/stdc++.h>
using namespace std;
int x;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x;
  int ans = 0;
  while(x) {
    ans += x % 2;
    x /= 2;
  }
  cout << ans;
}