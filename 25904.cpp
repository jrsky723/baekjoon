#include<bits/stdc++.h>
using namespace std;

int n,x;
int a[101];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  while(1) {
    for (int i = 0; i < n; i++) {
      if (x++ > a[i]) {
        cout << i + 1;
        return 0;
      }
    }
  }
}