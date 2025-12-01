#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s,ans;
int get_num(char c){
    if(c>='0'&&c<='9') return c-'0';
    if(c>='A'&&c<='Z') return 10+c-'A';
}
char get_char(int c){
    if(c<10) return c+'0';
    return c-10+'A';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s>>m;
    int base=n,num=0;
    for(int i=0;i<s.size();i++){
        int a=get_num(s[i]);
        num=base*num+a;
    }
    if(num==0){
        cout<<0<<endl;
        return 0;
    }
    while(num){//注意高位在前
        char c=get_char(num%m);//处理的是低位
        ans+=c;
        num/=m;
    }
    reverse(ans.begin(),ans.end());//所以要翻转  
    cout<<ans<<endl;
    return 0;
}