#include <bits/stdc++.h>
using namespace std;
int n;
int op[4];  //+,-,x,%
int num[101];
int mx = -0x7f7f7f7f;
int mn = 0x7f7f7f7f;
int cal(int x, int op, int y) {
  if (op == 0)
    return x + y;
  else if (op == 1)
    return x - y;
  else if (op == 2)
    return x * y;
  else
    return x / y;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  for (int i = 0; i < 4; i++) cin >> op[i];
  vector<int> mask;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < op[i]; j++) mask.push_back(i);

  do {
    int result = num[0];
    for (int i = 0; i < n - 1; i++) result = cal(result, mask[i], num[i + 1]);
    mx = max(mx, result);
    mn = min(mn, result);
  } while (next_permutation(mask.begin(), mask.end()));
  cout << mx << '\n' << mn;
}