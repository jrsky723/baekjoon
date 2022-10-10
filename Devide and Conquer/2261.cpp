#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second
vector<pii> p;
int n;

int dist(pii &p1, pii &p2) {
  int distX = p1.X - p2.X;
  int distY = p1.Y - p2.Y;
  return distX * distX + distY * distY;
}

int closestDist(int st, int en) {
  if (en - st <= 2) return dist(p[st], p[st + 1]);
  int CDL, CDR, d;
  int mid = (st + en) / 2;
  int mdX = p[mid].X;
  CDL = closestDist(st, mid);
  CDR = closestDist(mid, en);
  d = min(CDL, CDR);
  vector<pii> in;
  for (int i = st; i < en; i++) {
    if ((p[i].X - mdX) * (p[i].X - mdX) >= d) continue;
    in.push_back(p[i]);
  }
  sort(in.begin(), in.end(), [](auto &a, auto &b) {
    if (a.Y == b.Y) return a.X < b.X;
    return a.Y < b.Y;
  });
  int sz = in.size();
  for (int i = 0; i < sz - 1; i++)
    for (int j = i + 1; j < sz; j++) {
      int yDist = in[j].Y - in[i].Y;
      if (yDist*yDist >= d) break;
      d = min(d, dist(in[i], in[j]));
    }
  return d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n; i++) cin >> p[i].X >> p[i].Y;
  sort(p.begin(), p.end());
  cout << closestDist(0, n);
}