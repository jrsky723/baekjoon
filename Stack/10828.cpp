#include<bits/stdc++.h>
using namespace std;
const int MX = 10000;
int stc[MX];
int pos = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    while(N--){
        string s;
        cin>>s;
        if(s == "push"){
            int i;
            cin>>i;
            stc[pos++] = i;
        }
        else if(s == "pop"){
            if(pos) {
                cout<<stc[--pos]<<'\n';
                stc[pos] = 0;
            }
            else cout<<-1<<'\n';
        }
        else if(s == "size"){
            cout<<pos<<'\n';
        }
        else if(s == "empty"){
            if(pos) cout<<0<<'\n';
            else cout<<1<<'\n';
        }
        else{
            if(pos) cout<<stc[pos-1]<<'\n';
            else cout<<-1<<'\n';
        }
    }
}