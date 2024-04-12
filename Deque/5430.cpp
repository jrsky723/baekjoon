#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    string cmds;
    cin >> cmds;
    int n;
    cin >> n;
    string arr_s;
    cin >> arr_s;

    vector<int> vec;
    int temp = 0;
    for (auto c : arr_s) {
      if (c == '[') continue;
      if (c == ',' || c == ']') {
        vec.push_back(temp);
        temp = 0;
        continue;
      }
      temp = temp * 10 + (c - '0');
    }

    bool reversed = false;
    bool errored = false;
    int f_cnt = 0, b_cnt = 0, total = n;
    for (auto cmd : cmds) {
      if (cmd == 'R')
        reversed = !reversed;
      else {
        if (total == 0) {
          errored = true;
          break;
        }
        total--;
        if (reversed)
          b_cnt++;
        else
          f_cnt++;
      }
    }
    if (errored) {
      cout << "error" << '\n';
      continue;
    }
    cout << '[';
    if (!reversed) {
      for (int i = f_cnt; i < n - b_cnt; i++) {
        cout << vec[i];
        if (i != n - b_cnt - 1) cout << ',';
      }
    } else {
      for (int i = n - b_cnt - 1; i >= f_cnt; i--) {
        cout << vec[i];
        if (i != f_cnt) cout << ',';
      }
    }
    cout << "]\n";
  }
}
// 정답코드
//  Authored by : BaaaaaaaaaaarkingDog
//  Co-authored by : -
//  http://boj.kr/e93d3fd7a3bc43179af06505c3f524b0
// #include <bits/stdc++.h>
// using namespace std;
//
// void parse(string& tmp, deque<int>& d) {
//     int cur = 0;
//     for (int i = 1; i + 1 < tmp.size(); i++)
//     {
//         if (tmp[i] == ',') {
//             d.push_back(cur);
//             cur = 0;
//         }
//         else {
//             cur = 10 * cur + (tmp[i] - '0');
//         }
//     }
//     if (cur != 0)
//         d.push_back(cur);
// }
//
// void print_result(deque<int>& d) {
//     cout << '[';
//     for (int i = 0; i < d.size(); i++)
//     {
//         cout << d[i];
//         if (i + 1 != d.size())
//             cout << ',';
//     }
//     cout << "]\n";
// }
//
// int t;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> t;
//     while (t--) {
//         deque<int> d;
//         int rev = 0;
//         int n;
//         bool isWrong = false;
//         string query, tmp;
//         cin >> query;
//         cin >> n;
//         cin >> tmp;
//         parse(tmp, d);
//         for (char c : query)
//         {
//             if (c == 'R')
//                 rev = 1 - rev;
//             else {
//                 if (d.empty()) {
//                     isWrong = true;
//                     break;
//                 }
//                 if (!rev) d.pop_front();
//                 else d.pop_back();
//             }
//         }
//         if (isWrong)
//             cout << "error\n";
//         else {
//             if (rev) reverse(d.begin(), d.end());
//             print_result(d);
//         }
//     }
// }