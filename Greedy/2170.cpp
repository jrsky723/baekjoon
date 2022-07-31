#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> lines;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    lines.push_back({x, y});
  }
  sort (lines.begin(), lines.end());
  int s,t;
  tie(s, t) = lines[0];
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int a, b;
    tie(a, b) = lines[i];
    if (a <= t && t <= b) t = b;
    else if (a > t) {
      ans += t - s;
      tie(s, t) = {a,b};
    }
  }
  cout << ans + t - s;
}

//정답코드
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/c5472861d2ee4a1e8f8c3c60f477f0bc
// #include <bits/stdc++.h>
// using namespace std;

// #define X first
// #define Y second

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   vector<pair<int,int>> events;  
//   int n;
//   cin >> n;
//   while(n--){
//     int l, r;
//     cin >> l >> r;
//     events.push_back({l, 1});
//     events.push_back({r, -1});
//   }
//   sort(events.begin(), events.end());
//   int cnt = 0; // 현재 선의 개수
//   int tot = 0; // 전체 길이(= 답)
//   int loc = -1e9; // 현재 위치
//   for(auto event : events){
//     if(cnt > 0) tot += (event.X - loc);
//     loc = event.X;
//     cnt += event.Y;
//   }
//   cout << tot;
// }