#include <bits/stdc++.h>
using namespace std;

#define N get<0>
#define K get<1>
#define E get<2>
#define M get<3>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<tuple<string, int, int, int>> vec;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name; 
    int kook, eng, math;
    cin >> name >> kook >> eng >> math;
    vec.push_back({name, kook, eng, math}); //처음부터 -를 입력할것
  }
  sort(vec.begin(), vec.end(), [&](auto p1, auto p2) {
    if (K(p1) == K(p2)) {
      if (E(p1) == E(p2)) {
        if (M(p1) == M(p2))
          return N(p1) < N(p2);
        else
          return M(p1) > M(p2);
      } else
        return E(p1) < E(p2);
    } else
      return K(p1) > K(p2);
  });
  for (auto v : vec) cout << N(v) << '\n';
}
//정답코드
// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/9383c0972bbe43c28706a98f9d3e84c4
// #include <bits/stdc++.h>
// using namespace std;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int N;
//   cin >> N;
//   vector<tuple<int, int, int, string>> students;
//   while (N--) {
//     string name;
//     int kor, eng, math;
//     cin >> name >> kor >> eng >> math;
//     students.push_back({-kor, eng, -math, name});
//   }
//   sort(students.begin(), students.end());
//   for (auto& s : students)
//     cout << get<3>(s) << '\n';
// }