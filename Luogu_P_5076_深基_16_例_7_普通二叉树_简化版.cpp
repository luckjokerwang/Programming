#include <bits/stdc++.h>
using namespace std;
// #define int long long
multiset<int> mlst;//其实set也行
int q,op,x;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>q;
    while(q--){
        cin>>op>>x;
        switch (op)
        {
        case 1:
            {auto it=mlst.lower_bound(x);
            int rank=distance(mlst.begin(),it)+1;
            cout<<rank<<endl;
            break;}
        case 2:
            {auto it =mlst.begin();
            advance(it,x-1);
            cout<<*it<<endl;
            break;}
        case 3:
            {auto it =mlst.lower_bound(x);
            if(it==mlst.begin()){
                cout<<-2147483647<<endl;
            }
            else{
                
                cout<<*(--it)<<endl;
            }
            break;}
        case 4:
            {auto it=mlst.upper_bound(x);
            if(it==mlst.end()){
                cout<<2147483647<<endl;
            }
            else{
                cout<<*it<<endl;
            }
            break;
        }
        case 5:
            { mlst.insert(x);
            break;}
        default:
            break;
        }
    }
    return 0;
}