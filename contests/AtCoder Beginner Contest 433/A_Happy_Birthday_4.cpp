#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,y,z;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>x>>y>>z;
    for(int i=0;i<=10000;i++){
        int cur_x =x+i;
        int cur_y =y+i;
        if(cur_x==cur_y*z){
            cout<<"Yes"<<endl;
            return 0;
        }
        if(cur_x<cur_y*z){
            cout<<"No"<<endl;
            return 0;
        }
    }
}