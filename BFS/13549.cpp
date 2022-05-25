#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000; //0부터 시작일 때 범위를 생각하자.
int dist[MAX + 1];  
int main() {  //간선비용이 다른것이 포함되어있을 때는 나누어서 생각할 것
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(dist, dist + MAX + 1, -1);
  int N, K;
  cin >> N >> K;
  queue<int> Q;
  Q.push(N);
  dist[N] = 0;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int next : {cur - 1, cur + 1, cur * 2}) {
      if (next < 0 || next > MAX) continue;
      int d = next == cur*2 ? dist[cur] : dist[cur] + 1;
      if (dist[next] == -1 || dist[next] > d){
        dist[next] = d;
        Q.push(next);
      }
    }
  }
  cout << dist[K];
}

//정답코드
// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/39302be343944bda8d83b89a00b24759
// #include <bits/stdc++.h>
// using namespace std;

// const int LMT = 100001;
// int board[LMT+2];
// int sis, bro;
// queue<int> Q;
// void teleport(int num) {
//   int tmp = num;
//   if (!tmp) return;
//   while (tmp < LMT && !board[bro]) {
//     if (!board[tmp]) {
//       board[tmp] = board[num];
//       Q.push(tmp);
//       if (tmp == bro) return;
//     }
//     tmp <<= 1;
//   }
// }
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> sis >> bro;
//   board[sis] = 1;
//   Q.push(sis);
//   teleport(sis);
//   while (!board[bro]) {
//     int v = Q.front(); Q.pop();
//     vector<int> nvLst = { v + 1, v - 1 };
//     for (int nv : nvLst) {
//       if (nv < 0 || LMT <= nv) continue;
//       if (board[nv]) continue;
//       board[nv] = board[v] + 1;
//       Q.push(nv);
//       teleport(nv);
//     }
//   }
//   cout << board[bro]-1;
// }

/*
teleport 함수를 이용해 현재 보고 있는 v / nv의 2의 거듭제곱을 한 번에 처리하는 방식으로 풀이한 코드
*/