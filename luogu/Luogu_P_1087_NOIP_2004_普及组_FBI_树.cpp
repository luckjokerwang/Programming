#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
char check(int idx,int size){
    char c=' ';
    for(int i=idx;i<idx+size;i++){
        if(c==' ' && s[i]=='0') c='B';
        if(c==' ' && s[i]=='1') c='I';
        if((c=='B' && s[i]!='0') || (c=='I' && s[i]!='1')){
            return 'F';
        }
    }
    return c;
}
void dfs(int l,int size){
    if(size==0) return;
    dfs(l, size/2);                 // left half starts at l
    dfs(l+size/2,size/2); // right half starts at l+size/2
    char c = check(l, size);
    cout << c;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    dfs(0, s.size()); // or dfs(0, 1<<n)
    cout << '\n';
    return 0;
}