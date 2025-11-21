#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Person {
    string name;
    int id;
    int y;
    int m;
    int d;
} p[1000];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        p[i].id=i;
        cin>>p[i].name>>p[i].y>>p[i].m>>p[i].d;
    }
    sort(p,p+n,[](Person a,Person b){
        if(a.y!=b.y) return a.y<b.y;
        if(a.m!=b.m) return a.m<b.m;
        if(a.d!=b.d) return a.d<b.d;
        return a.id>b.id;
    });
    for(int i=0;i<n;i++){
        cout<<p[i].name<<endl;
    }
}