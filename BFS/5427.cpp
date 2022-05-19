#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int Fdist[1001][1001];
int Sdist[1001][1001];
char board[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int T, w, h;
queue<pair<int, int>> FQ;
queue<pair<int, int>> SQ;
void escape() {
  while (!SQ.empty()) {
    pair<int, int> cur = SQ.front();
    SQ.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
        cout << Sdist[cur.X][cur.Y] + 1 << '\n';
        return;
      }
      if (board[nx][ny] == '#' || Sdist[nx][ny] >= 0) continue;
      if (Sdist[cur.X][cur.Y] + 1 >= Fdist[nx][ny] && Fdist[nx][ny] != -1)
        continue;
      Sdist[nx][ny] = Sdist[cur.X][cur.Y] + 1;
      SQ.push({nx, ny});
    }
  }
  cout<<"IMPOSSIBLE\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        Fdist[i][j] = Sdist[i][j] = -1;
        cin >> board[i][j];
        if (board[i][j] == '*'){
          FQ.push({i, j});
          Fdist[i][j] = 0;
        }
        else if (board[i][j] == '@'){
          SQ.push({i, j});
          Sdist[i][j] = 0;
        }
      }
    }
    while (!FQ.empty()) {
      pair<int, int> cur = FQ.front(); FQ.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(board[nx][ny] == '#' || Fdist[nx][ny] >= 0) continue;
        Fdist[nx][ny] = Fdist[cur.X][cur.Y] + 1;
        FQ.push({nx,ny});
      }
    }
    escape();
    while(!SQ.empty()) SQ.pop();
  }
}

//정답코드
// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/93037793e6254ce1aa0773e99fb4107f
// #include <bits/stdc++.h>
// using namespace std;
// #define X first
// #define Y second
// int TC, bX, bY;
// int board[1002][1002];
// int visF[1002][1002];
// int visS[1002][1002];
// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> TC;
//   for (int testNo = 0; testNo < TC; testNo++) {
//     bool escape = false;
//     queue<pair<int, int>> Qf = {}, Qs = {};
//     cin >> bY >> bX;
//     for (int i = 0; i < bX; i++) {
//       fill(visF[i], visF[i] + bY, 0);
//       fill(visS[i], visS[i] + bY, 0);
//     }
//     for (int i = 0; i < bX; i++)
//       for (int j = 0; j < bY; j++) {
//         char c;
//         cin >> c;
//         if (c == '#') board[i][j] = -1;
//         else {
//           if (c == '@') {
//             Qs.push({i, j});
//             visS[i][j] = 1;
//           } 
//           else if (c == '*') {
//             Qf.push({i, j});
//             visF[i][j] = 1;
//           }
//           board[i][j] = 0;
//         }
//       }
//     while (!Qf.empty()) {
//       auto v = Qf.front();
//       Qf.pop();
//       for (int k = 0; k < 4; k++) {
//         int nx = v.X + dx[k];
//         int ny = v.Y + dy[k];
//         if (nx < 0 || bX <= nx || ny < 0 || bY <= ny) continue;
//         if (board[nx][ny] == -1) continue;
//         if (visF[nx][ny]) continue;
//         visF[nx][ny] = visF[v.X][v.Y] + 1;
//         Qf.push({nx, ny});
//       }
//     }
//     while ((!Qs.empty()) && (!escape)) {
//       auto v = Qs.front();
//       Qs.pop();
//       for (int k = 0; k < 4; k++) {
//         int nx = v.X + dx[k];
//         int ny = v.Y + dy[k];
//         if (nx < 0 || bX <= nx || ny < 0 || bY <= ny) {
//           cout << visS[v.X][v.Y] << '\n';
//           escape = true;
//           break;
//         }
//         if (board[nx][ny] == -1) continue;
//         if (visS[nx][ny]) continue;
//         if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[v.X][v.Y] + 1) continue;
//         visS[nx][ny] = visS[v.X][v.Y] + 1;
//         Qs.push({nx, ny});
//       }
//     }
//     if (!escape) cout << "IMPOSSIBLE" << '\n';
//   }
// }