#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
map<string, int>  c2i;
string city[102];
int nailCost[102][102], origCost[102][102];
int nailNxt[102][102], origNxt[102][102];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, r, m ,k;
  cin >> n >> r;

  int cityNum = 0;
  for (int i = 1; i <= n; i++) {
    string cityName;
    cin >> cityName;
    if  (c2i[cityName] == 0) {
      c2i[cityName] = ++cityNum;
      city[cityNum] = cityName;
    }
  }
  cin >> m;
  vector<int> dest;
  for (int i = 0; i < m; i++) {
    string cityName;
    cin >> cityName;
    dest.push_back(c2i[cityName]);
  }

  for (int i = 1; i <= n; i++) {
    fill(nailCost[i] + 1, nailCost[i] + 1 + n, INF);
    fill(origCost[i] + 1, origCost[i] + 1 + n, INF);
  }
  for (int i = 1; i <= n; i++) nailCost[i][i] = origCost[i][i] = 0;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string type, stName, toName;
    int cost, st, to;
    cin >> type >> stName >> toName >> cost;
    st = c2i[stName], to = c2i[toName];
    int temp = origCost[st][to];
    if (temp > 2 * cost) temp = 2 * cost;
    origCost[st][to] = origCost[to][st] = temp;
    temp = nailCost[st][to];
    if (type == "Mugunghwa" || type == "ITX-Saemaeul" ||
        type == "ITX-Cheongchun") {
          temp = 0;
    }
    else if (type == "S-Train" || type == "V-Train") {
      if (temp > cost) temp = cost;
    }
    else {
      if (temp > 2 *cost) temp = 2 * cost;
    }
    nailCost[st][to] = nailCost[to][st] = temp;
    nailNxt[st][to] = origNxt[st][to] = to;
    nailNxt[to][st] = origNxt[to][st] = st;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (nailCost[i][j] > nailCost[i][k] + nailCost[k][j]) {
          nailCost[i][j] = nailCost[i][k] + nailCost[k][j];
          nailNxt[i][j] = nailNxt[i][k];
        }
        if (origCost[i][j] > origCost[i][k] + origCost[k][j]) {
          origCost[i][j] = origCost[i][k] + origCost[k][j];
          origNxt[i][j] = origNxt[i][k];
        }
      }
    }
  }
  long long nailSum = 0, origSum = 0;
  int nailCur, origCur;
  nailCur = origCur = dest[0];
  for (int i = 1; i < dest.size(); i++){
    int to = dest[i];
    while(nailCur != to) {
      nailSum += nailCost[nailCur][nailNxt[nailCur][to]];
      nailCur = nailNxt[nailCur][to];
    }
    while (origCur != to) {
      origSum += origCost[origCur][origNxt[origCur][to]];
      origCur = origNxt[origCur][to];
    }
  }
  if (nailSum + 2 * r < origSum) cout << "Yes";
  else cout << "No";
}