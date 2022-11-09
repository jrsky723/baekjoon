#include <bits/stdc++.h>
using namespace std;

int n;
int a[3], mxDP[3], mnDP[3];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) cin >> a[j]; 
    mxDP[0] = max(mxDP[0], mxDP[1]);
    mxDP[2] = max(mxDP[1], mxDP[2]);
    mxDP[1] = max(mxDP[0], mxDP[2]);
    mnDP[0] = min(mnDP[0], mnDP[1]);
    mnDP[2] = min(mnDP[1], mnDP[2]);
    mnDP[1] = min(mnDP[0], mnDP[2]);
    for (int j = 0; j < 3; j++) mxDP[j] += a[j], mnDP[j] += a[j];
  }
  cout << *max_element(mxDP, mxDP + 3) << ' ' << *min_element(mnDP, mnDP + 3);
}