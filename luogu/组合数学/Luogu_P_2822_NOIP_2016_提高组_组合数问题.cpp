#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,k,n,m;
int c[2025][2025],s[2005][2005];
void init(){
    for(int i=0;i<=2000;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
        }
    }
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=2000;j++){
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(j<=i&&c[i][j]==0)
                s[i][j]+=1;
        }

    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t>>k;
    init();
    while(t--){
        cin>>n>>m;
        if(m>n) m=n;
        cout<<s[n][m]<<endl;
    }
    return 0;
}