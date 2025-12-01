#include <bits/stdc++.h>
using namespace std;
#define int long long
__int128 C[150][150];
void print(__int128 x){
    if(x==0){
        cout<<0;
        return ;
    }
    string s="";
    while(x>0){
        s+=char((x%10)+'0');
        x/=10;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<=n+max(a,b);i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    __int128 ans=C[n+a][a]*C[n+b][b];
    print(ans);
    return 0;
}