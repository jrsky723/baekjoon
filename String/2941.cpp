#include <bits/stdc++.h>

using namespace std;

string a_list[8] = {
    "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=",
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  for (auto t_s : a_list) {
    while (s.find(t_s) != -1) {
      int idx = s.find(t_s);
      s.replace(idx, t_s.length(), "0");
    }
  }
  cout << s.length() << '\n';
}