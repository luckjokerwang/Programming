#include <bits/stdc++.h>
using namespace std;
#define int long long
set<int> st;
int m,op,x;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>m;
    while(m--){
        cin>>op>>x;
        if(op==1){
            if(!st.count(x)) st.insert(x);
            else {
                cout<<"Already Exist"<<endl;
            }
        }
        if(op==2){
            if(st.empty()) {
                cout<<"Empty"<<endl;
                continue;
            }
            auto it=st.lower_bound(x);
            int ans;
            
            if(it==st.end()){
                // 所有木材都比x小，取最大的
                ans=*st.rbegin();
            }
            else if(it==st.begin()){
                // 所有木材都>=x，取最小的
                ans=*it;
            }
            else{
                // 有比x大的也有比x小的
                int x1=*it;  // >=x 的最小值
                int x2=*(--it);  // <x 的最大值
                // 比较距离，距离相同取小的
                ans=(x-x2)<=(x1-x)?x2:x1;
            }
            cout<<ans<<endl;
            st.erase(ans);
        }
    }
    return 0;
}