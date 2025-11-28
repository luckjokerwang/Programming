// //代码超时，用map<string,string>
// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// string s,name,father,son;
// const int MANX=5e4+9;
// vector<string> v;
// set<string> st;
// // map<string,int> mp;
// // map<int ,string>rmp;
// char op;
// int fa[MANX],fx,fy;
// string get_name_by_id(int idx){
//     return *next(st.begin(),idx);
// }
// int find(int x){
//     if(x==fa[x]) return x;
//     return fa[x]=find(fa[x]);
// }
// void join(int x,int y){
//     int fx=find(x);
//     int fy=find(y);
//     if(fx!=fy){
//         fa[fx]=fy;
//     }
// }
// int get_id(string s){
//     // return lower_bound(st.begin(),st.end(),s)-st.begin(); 
//     //set 的迭代器：双向迭代器（Bidirectional Iterator），不支持直接相减
//     auto it=st.lower_bound(s);
//     return distance(st.begin(),it);
// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     while (cin >> s &&s!= "$")
//     {
//         op=s[0];
//         name=s.substr(1);
//         st.insert(name);
//         v.push_back(s);
//         // if(!st.count(name)){
//         // st.insert(name);
//         // mp[name] = ++idx;
//         // rmp[idx]=name;
//         // }
//         // if(op=='#') father=name;
//         // if(op=='+') {
//         //     son=name;
//         //     join(son,name);
//         // }
//     }
//     for(int i=0;i<st.size();i++){
//         fa[i]=i;
//     }
//     for(string s:v){
//         op=s[0];
//         name=s.substr(1);
//         if(op=='#') {father=name;  fy=get_id(father);}
//         if(op=='+') {
//             son=name;
//             fx=get_id(son);
//             join(fx,fy);
//         }
//         if(op=='?'){
//             son =name;
//             fx=get_id(son);
//             fy=find(fx);
//             father=get_name_by_id(fy);
//             cout<<son<<" "<<father<<endl;
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
map<string,string> mp;//mp[son]=father
string s,name,father,son;
char op;
string find(string son){
    if(!mp.count(son)) return son;
    if(mp[son]==son) return son;
    return mp[son]=find(mp[son]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>s&&s!="$"){
        op=s[0];
        name =s.substr(1);
        if(op=='#'){
            father=name;
        }
        if(op=='+'){
            son=name;
            mp[son]=father;
        }
        if(op=='?'){
            father=find(name);
            cout<<name<<" "<<father<<endl;
        }
    }
}