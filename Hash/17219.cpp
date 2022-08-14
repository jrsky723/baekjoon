#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> password;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string site, pw;
    cin >> site >> pw;
    password[site] = pw;
  }
  for (int i = 0; i < m; i++) {
    string site;
    cin >> site;
    cout << password[site] << '\n';
  }
}