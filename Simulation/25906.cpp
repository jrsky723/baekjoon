#include <bits/stdc++.h>
using namespace std;
int skill[6][103];  // skill[i][0] : max Level
int T, K, ans;
struct Armor {
  int price = 0;
  int LevelUP[6] = {};
  Armor(int price) {
    this->price = price;
    for (int i = 1; i <= 5; i++) cin >> LevelUP[i];
  }
};

vector<Armor *> ArmorList[3];
void input() {
  cin >> T >> K;
  for (int i = 1; i <= 5; i++) {
    cin >> skill[i][0];
    for (int j = 1; j <= skill[i][0]; j++) cin >> skill[i][j];
  }
  for (int srt = 0; srt < 3; srt++) {  // srt = 종류| 0:머리, 1:몸, 2:하의
    int M;
    cin >> M;
    vector<int> v(M);
    for (int i = 0; i < M; i++) cin >> v[i];
    for (int i = 0; i < M; i++) {
      Armor *a = new Armor(v[i]);
      ArmorList[srt].push_back(a);
    }
  }
}
vector<Armor *> curArmor(3, NULL);

int sum(vector<int> lv) {
  int ret = 0;
  for (int i = 1; i <= 5; i++) {
    if (lv[i] == 0) continue;
    if (lv[i] > skill[i][0])
      ret += skill[i][skill[i][0]];
    else
      ret += skill[i][lv[i]];
  }
  return ret;
}

void dfs(int srt) {
  if (srt == 3) {
    vector<int> lv(6, 0);
    for (auto w : curArmor) {
      if (w == NULL) continue;
      for (int i = 1; i <= 5; i++) lv[i] += w->LevelUP[i];
    }
    if (T >= K) {
      for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
          if (i == j || lv[j] == 0) continue;
          lv[i]++, lv[j]--;
          ans = max(sum(lv), ans);
          lv[i]--, lv[j]++;
        }
      }
    }
    ans = max(sum(lv), ans);
    return;
  }
  for (auto w : ArmorList[srt]) {
    if (T >= w->price) {  //방어구를 삼
      T -= w->price, curArmor[srt] = w;
      dfs(srt + 1);
      T += w->price, curArmor[srt] = NULL;
    }
  }
  dfs(srt + 1);  // 안 삼
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  input();
  dfs(0);
  cout << ans << '\n';
}