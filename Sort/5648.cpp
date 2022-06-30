#include <bits/stdc++.h>
using namespace std;

vector<long long> vec;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    vec.push_back(stoll(str));
  }
  stable_sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) cout << vec[i] << '\n';
}