#include <bits/stdc++.h>
using namespace std;

#define F get<0>
#define O get<1>
#define V get<2>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<pair<long long, int>> v1;  // value, order
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    long long ll;
    cin >> ll;
    v1.push_back({ll, i});
  }
  sort(v1.begin(), v1.end());
  vector<tuple<int, int, long long>> v2 = {{0, 0, 0}};
  for (int i = 0; i < n; i++) {
    if (v1[i].first == V(v2.back()))
      F(v2.back())++;
    else
      v2.push_back({1, v1[i].second, v1[i].first});
  }
  sort(v2.begin(), v2.end(), [&](auto t1, auto t2) {
    if (F(t1) == F(t2))
      return O(t1) < O(t2);
    else
      return F(t1) > F(t2);
  });
  for (auto v : v2)
    for (int i = 0; i < F(v); i++) cout << V(v) << ' ';
}

//정답코드
// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/0fd334ddb06d417689cd6c944d5a0585
// #include <bits/stdc++.h>
// using namespace std;

// #define X first
// #define Y second

// bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
//   return a.X > b.X;
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n, c;
//   cin >> n >> c;
//   vector<pair<int, int>> arr; // pair : {cnt, num}
//   for (int i = 0; i < n; i++) {
//     int x;
//     cin >> x;
//     bool chk = false;
//     for (auto &a : arr) {
//       if (a.Y == x) {
//         chk = true;
//         a.X++;
//         break;
//       }
//     }
//     if (!chk) arr.push_back({1, x});
//   }
//   stable_sort(arr.begin(), arr.end(), cmp);

//   for (auto b : arr)
//     while (b.X--) cout << b.Y << ' ';
// }