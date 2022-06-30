#include <bits/stdc++.h>
using namespace std;

string seriel[51];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> seriel[i];
  stable_sort(seriel, seriel + n, [&](string s1, string s2) {
    if (s1.length() != s2.length())
      return s1.length() < s2.length();
    else {  //return 에는 else 쓰지말것
      int digit_s1 = 0, digit_s2 = 0;
      for (auto c : s1)
        if (c >= '0' && c <= '9') digit_s1 += c - '0';
      for (auto c : s2)
        if (c >= '0' && c <= '9') digit_s2 += c - '0';
      if (digit_s1 != digit_s2)
        return digit_s1 < digit_s2;
      else {
        return s1 < s2;
      }
    }
  });
  for (int i = 0; i < n; i++) cout << seriel[i] << '\n';
}