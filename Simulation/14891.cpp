#include <bits/stdc++.h>
using namespace std;

string gear[5];
void rotate(int g, int dir) {
  string temp = gear[g];
  for (int i = 0; i < 8; i++) gear[g][(i + dir + 8) % 8] = temp[i];
}
void run(int g, int dir) {
  int ED[5] = {};
  ED[g] = dir;
  queue<int> Q;
  Q.push(g);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int i : {1, -1}) {
      int next = cur + i;
      if (next < 1 || next > 4 || ED[next]) continue;
      if (i == 1) {
        if (gear[cur][2] == gear[next][6]) continue;
      } else {
        if (gear[cur][6] == gear[next][2]) continue;
      }
      Q.push(next);
      ED[next] = -ED[cur];
    }
  }
  for (int i = 1; i <= 4; i++) {
    if (ED[i]) rotate(i, ED[i]);
  }
}
int main() {
  int k;
  int ans = 0;
  for (int i = 1; i <= 4; i++) cin >> gear[i];
  cin >> k;
  while (k--) {
    int g, dir;
    cin >> g >> dir;
    run(g, dir);
  }
  for (int i = 1; i <= 4; i++) ans += (gear[i][0] - '0') * (1 << (i - 1));
  cout << ans;
}
//정답코드
// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/dfcfa653b8494b3082959f248edfb200
// #include <bits/stdc++.h>
// using namespace std;

// string board[4];

// // x : 번호, dir : 방향, 1번의 회전을 처리하는 함수
// void go(int x, int dir) {
//   int dirs[4] = {};
//   dirs[x] = dir;
//   // 왼쪽으로 회전을 전파
//   int idx = x;
//   while (idx > 0 && board[idx][6] != board[idx-1][2]){
//     dirs[idx-1] = -dirs[idx];
//     idx--;
//   }
  
//   // 오른쪽으로 회전을 전파
//   idx = x;
//   while (idx < 3 && board[idx][2] != board[idx+1][6]){
//     dirs[idx+1] = -dirs[idx];
//     idx++;
//   }

//   for(int i = 0; i < 4; i++) {
//     if(dirs[i] == -1)
//       rotate(board[i].begin(), board[i].begin()+1, board[i].end());    
//     else if(dirs[i] == 1)
//       rotate(board[i].begin(), board[i].begin()+7, board[i].end());
//   }
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
//   for (int i = 0; i < 4; i++) cin >> board[i];
//   int k;
//   cin >> k;
//   while (k--) {
//     int x, dir;
//     cin >> x >> dir;
//     go(x - 1, dir);
//   }
//   int ans = 0;
//   for (int i = 0; i < 4; i++)
//     if (board[i][0] == '1') ans += (1 << i);
//   cout << ans;
// }
