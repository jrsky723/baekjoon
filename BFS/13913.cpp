#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int prePos[MAX + 3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(prePos, prePos + MAX + 1, -1);
  int from, to;
  cin >> from >> to;
  queue<int> Q;
  Q.push(from);
  prePos[from] = from;
  while (prePos[to] == -1) {
    int cur = Q.front(); Q.pop();
    for (int next : {cur - 1, cur + 1, cur * 2}) {
      if (next < 0 || next > MAX) continue;
      if (prePos[next] != -1) continue;
      Q.push(next);
      prePos[next] = cur;
    }
  }
  deque<int> track = {to};
  while (track.front() != from)
    track.push_front(prePos[track.front()]);
  cout<<track.size() - 1<<'\n';
  for (int p : track) cout<<p<<' ';
}
