#include <bits/stdc++.h>
using namespace std;

int snow[605];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> snow[i];
  sort(snow, snow + n);
  vector<tuple<int, int, int>> snowman;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (snow[i] <= snow[j]) snowman.push_back({snow[i] + snow[j], i, j});
  sort(snowman.begin(), snowman.end());
  int ans = 0x7f7f7f7f;
  for (int i = 0; i < snowman.size() - 1; i++) {
    int ah, a1, a2;
    tie(ah, a1, a2) = snowman[i];
    for (int j = i + 1; j < snowman.size(); j++) {
      int bh, b1, b2;
      tie(bh, b1, b2) = snowman[j];
      if (a1 != b1 && a1 != b2 && a2 != b1 && a2 != b2) {
        ans = min(ans, abs(ah - bh));
        break;
      }
    }
  }
  cout << ans;
  return 0;
}

//투포인터 풀이
//출처 : https://ansohxxn.github.io/boj/20366/
// #include <bits/stdc++.h>

// using namespace std;

// struct Elem { int index1, index2, sum; };
// bool cmp(const Elem& a, const Elem& b) {
// 	return a.sum < b.sum;
// }

// int main() {
// 	//freopen("input.txt", "r", stdin);
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);

// 	int N;
// 	cin >> N;

// 	vector<int> snow(N);
// 	for (int i = 0; i < N; ++i)
// 		cin >> snow[i];

// 	sort(snow.begin(), snow.end()); // 눈덩이 크기 순으로 정렬 

// 	int answer = INT_MAX;
// 	for (int i = 0; i < N - 3; ++i) {
// 		for (int j = i + 3; j < N; ++j) {
// 			// i ~ j 범위의 양끝에서 시작
// 			// left 와 right 는 엘사의 눈덩이
// 			int left = i + 1;
// 			int right = j - 1;

// 			while (left < right) {
//                 int anna = snow[i] + snow[j]; // 안나 눈사람
//                 int elsa = snow[left] + snow[right]; // 엘사 눈사람
// 				int result = elsa - anna;
				
// 				answer = min(answer, abs(result)); 
				
// 				if (result > 0)  // 현재 엘사가 더 크다면 최소 키 차이를 구하기 위해선 앞으로 엘사가 더 작아져야 한다.
// 					right = right - 1;
// 				else  // 현재 엘사가 더 작다면 최소 키 차이를 구하기 위해선 앞으로 엘사가 더 커져야 한다.
// 					left = left + 1;
// 			}
// 		}
// 	}
// 	cout << answer;
// }