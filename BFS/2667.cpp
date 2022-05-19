#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[26];
bool vis[26][26];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N,cnt = 0;  //카운트를 분리해서 선언하자
  vector<int> v;
  cin>>N;

  for(int i = 0; i < N; i++) cin>>board[i];

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j] == '1' && !vis[i][j]){
        queue <pair<int,int>> Q;
        cnt++;
        int area = 0;
        Q.push({i,j}); vis[i][j] = true;
        while(!Q.empty()){
          pair<int,int> cur = Q.front(); Q.pop();
          area++;
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(vis[nx][ny] || board[nx][ny] == '0') continue;
            Q.push({nx,ny});
            vis[nx][ny] = true;
          }
        }
        v.push_back(area);
      }
    }
  }
  sort(v.begin(),v.end());
  cout<<cnt<<'\n';
  for(int i : v) cout<<i<<'\n';
}
//정답코드
// Authored by : 0silver00
// Co-authored by : -
// http://boj.kr/118e3a5900f94c4aae7aff09c263ef06
// #include <bits/stdc++.h>
// using namespace std;

// #define X first
// #define Y second
// int dx[4] = { 1, 0, -1, 0 };
// int dy[4] = { 0, 1, 0, -1 };
// int n;
// string board[27];
// int vis[27][27];

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> n;
//   for(int i = 0; i < n; i++) {
//     cin >> board[i];
//   }

//   int count = 0;
//   vector <int> ans;

//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       if (board[i][j] == '0' || vis[i][j] == 1)
//         continue;
//       queue < pair<int, int> > Q;
//       vis[i][j] = 1;
//       Q.push({ i, j });
//       int width = 1;
//       count++;
//       while (!Q.empty()) {
//         auto cur = Q.front();
//         Q.pop();
//         for (int dir = 0; dir < 4; dir++) {
//           int nx = cur.X + dx[dir];
//           int ny = cur.Y + dy[dir];
//           if (nx < 0 || nx >= n || ny < 0 || ny >= n)
//             continue;
//           if (board[nx][ny] == '0' || vis[nx][ny] == 1)
//             continue;
//           Q.push({ nx, ny });
//           vis[nx][ny] = 1;
//           width++;
//         }
//       }
//       ans.push_back(width);
//     }
//   }

//   cout << count << '\n';
//   sort(ans.begin(), ans.end());

//   for (int i : ans)
//     cout << i << '\n';

//   return 0; 
// }