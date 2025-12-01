#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,R;
string ans;
char get_char(int x)
{
    if(x>=0&&x<=9) return x+'0';
    return x-10+'A';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>R;
    //数学式：n=q*R+r;
    //问题：C++对负数取模，模为负数
    //n=(q+1)*R+(r-R) 
    int temp=n;
    while(n){
        int r=n%R;
        n/=R;
        if(r<0){
            r-=R;
            n+=1;
        }
        ans+=get_char(r);
    }
    reverse(ans.begin(),ans.end());
    cout<<temp<<"="<<ans<<"(base"<<R<<")"<<endl;
    return 0;
}