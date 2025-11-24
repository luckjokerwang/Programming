#include <bits/stdc++.h>
using namespace std;
// #define int long long
int r,x,y,s,xp,yp;
//思路:先求向量坐标,判断是不是原点,原点随便切
/* 再判断距离d,<r/2,有最大
>r/2,最大是正3角形
求面积: 极限思想等腰三角形
底:2*sqrt(r^2-d^2);
h=r+d;
area=(r+d)*sqrt(r^2-d^2);
判断是否大于S 非输出-1;
找边;
先找顶边; xi=x-r*ux,//反向延伸
在找垂点:mx=x+h*ux
其他点 x2=mx-w*uy//注意x用y,不要都在一条直线上了
. 变量定义混乱（不建议覆盖 d）
你复用了 d 变量，先表示“P点距离”，后表示“弦的垂距”。
虽然在逻辑上勉强跑得通，但非常容易把自己绕晕。
 建议：定义一个新变量 h_dist 来表示弦距离圆心的距离。
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>r>>x>>y>>s>>xp>>yp;
    double dx=xp-x;
    double dy=yp-y;
    double d=sqrt(dx*dx+dy*dy);
    double ux,uy;//向量坐标
    if(d<1e-9){
        ux=1.0;
        uy=0.0;
    }
    else{
        ux=dx/d;
        uy=dy/d;
    }
    if(d>=r/2.0){
        d=r/2.0;
    }
    double w=sqrt(r*r-d*d);
    double h=r+d;
    double max_area=w*h;
    if(max_area<s-1e-7){
        cout<<-1<<endl;
    }
    else{
        double x1=x-r*ux;
        double y1=y-r*uy;
        double mx=x+d*ux;
        double my=y+d*uy;
        double x2=mx-w*uy;
        double y2=my+w*ux;
        double x3=mx+w*uy;
        double y3=my-w*ux;
        cout<<fixed<<setprecision(8);
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3;
    }
    return 0;
}