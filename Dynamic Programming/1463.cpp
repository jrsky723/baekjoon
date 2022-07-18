#include <bits/stdc++.h>
using namespace std;

int D[1000001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 1000000; i++) {
    for (int nx : {3*i,2*i,1 + i}){
      if (nx > 1000000) continue;
      if(D[nx] > D[i] + 1 || !D[nx])
      D[nx] = D[i] + 1;
    }
  }
  int n;
  cin >> n;
  cout<< D[n];
}