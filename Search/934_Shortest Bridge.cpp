//关键字:深度优先搜索DFS,广度优先搜索BFS，用队列queue实现BFS，类模板pair
/*
本题实际是求两个岛屿之间的最短距离。岛屿初始值为1，海洋初始值为0
分2步：
1.所以先用任意搜索方法(这里用DFS)找到其中一个岛屿，令所有和该岛屿相连的岛屿值都变为2，同时记录下这些相连岛屿周围所有的海洋位置
2.用BFS从这些海洋位置依次层层向下搜索，当找到1就说明找到了孤立的岛屿，因为只有2座岛，所以找到1就可以返回这时候的层数了即最短桥。
*/
class Solution {
public:
    //主函数
    int shortestBridge(vector<vector<int>>& A) {
        int m=A.size(), n=A[0].size();
        queue<pair<int,int>> ocean;    //记录岛屿周围海洋的坐标
        //调用DFS找到第一座岛屿，找到即停止
        bool find =false;
        for(int i=0;i<m;++i){
            if(find) break;
            for(int j=0;j<n;++j){
                if(A[i][j]==1){
                    dfs(A,ocean,i,j);
                    find=true;
                    break;
                }
            }
        }
        //用BFS去找到第二座岛屿
        int bridge =0 ;
        int x,y;
        while(!ocean.empty()){
            ++bridge;
            int num=ocean.size();
            //一层层往下找
            while(num--){
                auto [r,c]=ocean.front();
                ocean.pop();
                for(int k=0;k<4;k++){
                    x=r+directions[k],y=c+directions[k+1];
                    if(x>=0 && x<m && y>=0 &&y<n){
                        if(A[x][y]==2){
                            continue;
                        }
                        if(A[x][y]==1){
                            return bridge;
                        }
                        if(A[x][y]==0){
                            A[x][y]=2;
                            ocean.push({x,y});
                        }
                    }
                }
            }
        }
        return 0;
    }
    
    vector<int> directions={-1,0,1,0,-1};
  
    //辅函数DFS
    void dfs(vector<vector<int>>& A,queue<pair<int,int>>& ocean, int i, int j){
        if(i<0 || j<0 ||i>=A.size() || j>=A[0].size() || A[i][j]==2){
            return;
        }
        if(A[i][j]==0){
            ocean.push({i,j});
            return;
        }
        A[i][j]=2;
        int x,y;
        //把第一座岛屿所有相连的1都给找来
        for(int k=0;k<4;++k){
            x=i+directions[k],y=j+directions[k+1];
            dfs(A,ocean,x,y);
        }

    }
};
