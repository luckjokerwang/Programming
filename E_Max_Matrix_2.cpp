#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin>>T)) return 0;
    while(T--){
        int N,M;
        cin>>N>>M;
        vector<int> X(N), Y(M);
        for(int i=0;i<N;i++) cin>>X[i];
        for(int j=0;j<M;j++) cin>>Y[j];

        long long LIM = 1LL * N * M;

        // 判范围与重复
        auto checkDistinct = [&](const vector<int>& a)->bool{
            unordered_set<int> st;
            for(int v: a){
                if(v < 1 || v > LIM) return false;
                if(st.count(v)) return false;
                st.insert(v);
            }
            return true;
        };
        if(!checkDistinct(X) || !checkDistinct(Y)){
            cout<<"No\n"; 
            continue;
        }

        // 建映射
        vector<int> rx(LIM+1,-1), cy(LIM+1,-1);
        for(int i=0;i<N;i++) rx[X[i]] = i;
        for(int j=0;j<M;j++) cy[Y[j]] = j;

        // 最大值 LIM 必须出现于 X 或 Y
        if(rx[LIM]==-1 && cy[LIM]==-1){
            cout<<"No\n";
            continue;
        }

        vector<vector<int>> A(N, vector<int>(M,0));
        vector<int> rowActive(N,0), colActive(M,0);

        // 维护已激活行、列集合
        vector<int> activeRows, activeCols;
        // 为 OTHER & ROW 类型需要找到列; 为 OTHER & COL 类型需要找到行
        // 对于每个行存储已激活列的迭代指针
        vector<int> nextColPos(N,0);
        vector<int> nextRowPos(M,0);

        bool ok = true;

        for(long long v=LIM; v>=1 && ok; --v){
            bool isRow = rx[v]!=-1;
            bool isCol = cy[v]!=-1;

            if(isRow && isCol){ // BOTH
                int r = rx[v], c = cy[v];
                if(A[r][c]!=0){ ok=false; break; }
                A[r][c] = (int)v;
                if(!rowActive[r]){
                    rowActive[r]=1;
                    activeRows.push_back(r);
                }
                if(!colActive[c]){
                    colActive[c]=1;
                    activeCols.push_back(c);
                }
            }else if(isRow){ // ROW only
                if(activeCols.empty()){ ok=false; break; }
                int r = rx[v];
                // 找一个激活列未占用
                bool placed = false;
                for(int &p = nextColPos[r]; p < (int)activeCols.size(); ++p){
                    int c = activeCols[p];
                    if(A[r][c]==0){
                        A[r][c] = (int)v;
                        placed = true;
                        break;
                    }
                }
                if(!placed){ // 可能新激活列出现后继续找
                    for(int c : activeCols){
                        if(A[r][c]==0){
                            A[r][c]= (int)v;
                            placed=true;
                            break;
                        }
                    }
                }
                if(!placed){ ok=false; break; }
                if(!rowActive[r]){
                    rowActive[r]=1;
                    activeRows.push_back(r);
                }
            }else if(isCol){ // COL only
                if(activeRows.empty()){ ok=false; break; }
                int c = cy[v];
                bool placed=false;
                for(int &p = nextRowPos[c]; p < (int)activeRows.size(); ++p){
                    int r = activeRows[p];
                    if(A[r][c]==0){
                        A[r][c]=(int)v;
                        placed=true;
                        break;
                    }
                }
                if(!placed){
                    for(int r : activeRows){
                        if(A[r][c]==0){
                            A[r][c]=(int)v;
                            placed=true;
                            break;
                        }
                    }
                }
                if(!placed){ ok=false; break; }
                if(!colActive[c]){
                    colActive[c]=1;
                    activeCols.push_back(c);
                }
            }else{ // OTHER
                if(activeRows.empty() || activeCols.empty()){ ok=false; break; }
                bool placed=false;
                // 简单扫描: 寻找已激活行列的空格
                for(int r : activeRows){
                    for(int c : activeCols){
                        if(A[r][c]==0){
                            A[r][c]=(int)v;
                            placed=true;
                            break;
                        }
                    }
                    if(placed) break;
                }
                if(!placed){ ok=false; break; }
            }
        }

        if(!ok){
            cout<<"No\n";
            continue;
        }
        // 输出
        cout<<"Yes\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(A[i][j]==0){ // 保险: 理论不应出现
                    cout<<1<<" ";
                }else cout<<A[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;

}