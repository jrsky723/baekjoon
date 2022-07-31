#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
queue<int> idx[101];
int order[105];
bool plug[105];
int n, k;

void plug_out() {
  int mx = 0;
  int mxIdx = 0;
  for (int i = 1; i <= k; i++) {
    if (plug[i] && mx < idx[i].front()) {
      mx = idx[i].front();
      mxIdx = i;
    }
  }
  plug[mxIdx] = false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> order[i];
    idx[order[i]].push(i);
  }
  for (int i = 1; i <= k; i++) idx[i].push(INF);
  int ans = 0, cnt = 0;
  for (int i = 0; i < k; i++) {
    idx[order[i]].pop();
    if (cnt == n) {
      if (plug[order[i]]) {
        continue;
      } else {
        plug_out();
        ans++;
        plug[order[i]] = true;
      }
    } else {
      if (!plug[order[i]]) {
        plug[order[i]] = true;
        cnt++;
      }
    }
  }
  cout << ans;
}

//정답코드
// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/03e21675c9ef49a8b6f1ee6838a44aeb
// #include <bits/stdc++.h>
// using namespace std;

// #define X first
// #define Y second

// int a[105]; // 전기용품의 사용 순서
// bool power[105]; // 해당 전기용품이 멀티탭에 꽂혀 있는가?

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
//   int n, k;
//   cin >> n >> k;
//   for (int i = 1; i <= k; i++) cin >> a[i];
//   int ans = 0;
//   int cnt = 0; // 멀티탭에 꽂혀 있는 전기용품의 개수
//   for (int i = 1; i <= k; i++) {
//     int cur = a[i];
//     if (power[cur]) continue; // 이미 꽂혀 있으면 넘어감
//     // 멀티탭에 자리가 남으면 그냥 꽂음
//     if (cnt < n) {
//       power[cur] = true;
//       cnt++;
//     }
//     else {
//       // 멀티탭에 꽂혀 있는 전기용품 중 a에서 앞으로 가장 빨리 나올 위치를 이름과 함께 저장함
//       vector<pair<int, int>> idx;
//       for (int x = 1; x <= k; x++) {
//         if (!power[x]) continue;
//         bool vis = false;
//         for (int y = i + 1; y <= k; y++) {
//           if (a[y] == x) {
//             idx.push_back({y, x});
//             vis = true;
//             break;
//           }
//         }
//         if (!vis) idx.push_back({k + 1, x}); // a에서 나오지 않으면 k + 1로 처리
//       }
//       sort(idx.begin(), idx.end(), greater<pair<int, int>>());
//       int target = idx[0].Y; // 가장 늦게 사용할 전기용품을 뽑고 cur을 꽂으면 됨
//       power[target] = false; ans++;
//       power[cur] = true;
//     }
//   }
//   cout << ans;
// }