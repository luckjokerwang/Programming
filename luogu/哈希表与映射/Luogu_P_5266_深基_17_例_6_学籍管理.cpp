#include <bits/stdc++.h>
using namespace std;
#define int long long
map<string,int> mp;
int q,op,score;
string s;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>q;
    while(q--){
        cin>>op;
        switch (op)
        {
        case 1:{
            cin>>s>>score;
            mp[s]=score;
            cout<<"OK"<<endl;
            break;}
        case 2:{
            cin>>s;
            if(!mp.count(s))
            cout<<"Not found"<<endl;
            else{
                cout<<mp[s]<<endl;
            }
            break;}
        case 3:{
            cin>>s;
            if(!mp.count(s))
            cout<<"Not found"<<endl;
            else{
                cout<<"Deleted successfully"<<endl;
                mp.erase(s);
            }
            break;}
        case 4:{
            cout<<mp.size()<<endl;
            break;}
        default:
            break;
        }
    }
    return 0;
}