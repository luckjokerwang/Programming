#include <bits/stdc++.h>
using namespace std;
#define int long long
int q,n;
stack<int> st;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>q;
    while(q--){
        cin>>n;
        while(!st.empty()){
            st.pop();
        }
        vector<int> v(n),p(n);
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        int idx=0;
        for(int i=0;i<n;i++){
            st.push(v[i]);
            while(!st.empty()&&st.top()==p[idx]){
                st.pop();
                idx++;
            }
        }
        if(st.empty()){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}