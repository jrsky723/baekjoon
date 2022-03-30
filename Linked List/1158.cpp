#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <int> v;     //정답에서는 queue를 이용하여 앞의 원소를 뒤로 
    vector <int> ans;   //보내고 pop으로 앞을 삭제 또는 원형리스트를 구현
    int N,K;
    cin>>N>>K;

    for(int i = 0; i < N; i++) 
        v.push_back(i+1);

    int cnt = 0;

    while(N){
        for(int i = 0; i < v.size(); i++){

            if(v[i]) cnt++;     // 0이 아닐 때 cnt증가

            if(cnt==K){         // cnt가 K와 같을때 원소를 0으로 변경, 정답에 추가
                ans.push_back(v[i]);
                v[i] = 0;
                cnt = 0;
                N--;
            }
        }
    }

    cout<<"<";  

    for(auto it = ans.begin(); it != ans.end()-1; it++) // 마지막 원소 제외하고 출력
        cout<<*it<<","<<" ";
    
    cout<<ans.back()<<">";  //마지막 원소
}

//정답 1 : 큐를 이용
// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/4ef85f8d8d834deb8b8ae054d249fff9
// #include <bits/stdc++.h>
// using namespace std;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n, k;
//   cin >> n >> k;
//   queue<int> Q;
//   for (int i = 1; i <= n; i++) Q.push(i);
//   cout << '<';
//   while (!Q.empty()) {
//     for (int i = 0; i < k - 1; i++) {
//       Q.push(Q.front());
//       Q.pop();
//     }
//     cout << Q.front();
//     Q.pop();
//     if (Q.size()) cout << ", ";
//   }
//   cout << '>';
// }

//정답 2 : 원형리스트 구현
// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/b7f7b82420c74d43b13c398fc6c73841
// #include <bits/stdc++.h>
// using namespace std;

// int N, K, len = 0;

// // 리스트에서 이전 노드/다음 노드를 가리키는 변수
// int pre[5001];
// int nxt[5001];
// // 요세푸스 순열을 저장하는 변수
// vector<int> v;

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> N >> K;

//   // 원형 연결 리스트 생성
//   // 맨 처음 노드와 마지막 노드가 서로를 가리키도록 지정
//   for(int i = 1; i <= N; ++i){
//     pre[i] = (i == 1) ? N : i - 1;
//     nxt[i] = (i == N) ? 1 : i + 1;
//     ++len;
//   }

//   int i = 1;
//   // 연결 리스트를 순회하며 순열 생성
//   for(int cur = 1; len != 0; cur = nxt[cur]){
//     // K 번째일 때 제거
//     if(i == K){
//       pre[nxt[cur]] = pre[cur];
//       nxt[pre[cur]] = nxt[cur];
//       v.push_back(cur);
//       i = 1;
//       --len;
//     } else ++i;
//   }

//   // 요세푸스 순열 출력
//   cout << "<";
//   for(size_t i = 0; i < v.size(); ++i) {
//     cout << v[i];
//     if(i != v.size() - 1) cout << ", ";
//   }
//   cout << ">";
// }