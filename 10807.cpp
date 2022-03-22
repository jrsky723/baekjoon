#include<bits/stdc++.h>
using namespace std;
int arr[201];   //전역에다 뒀지만 it's ok.
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,num,out;
    cin>>N;
    for(int i = 0; i < N; i++){ //while(N--) N번 반복하고, i가 필요없다면 while을 쓰자
        cin>>num;
        arr[num+100]++;
    }
    cin>>out;
    cout<<arr[out+100];
}

//정답 코드
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   // -100 <= v && v <= 100 이므로 음수도 저장할 수 있는 공간을 배열에 추가
//   int N, v, a[201] = {};
//   cin >> N;

//   // 입력값을 배열에 저장
//   while(N--){
//     int t;
//     cin >> t;
//     // 음수도 인덱스로 접근하기 위해 기존 인덱스+100으로 배열에 저장
//     a[t+100]++;
//   }

//   // v의 개수를 배열에서 확인
//   cin >> v;
//   cout << a[v+100];
// }