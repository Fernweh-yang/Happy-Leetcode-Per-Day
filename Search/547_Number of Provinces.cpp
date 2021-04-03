//关键字：深度优先搜索DFS,vector,递归实现
/*
遍历每一座城市，只有为1说明相连
[i][j]=1说明i城和j城相连，把其值变为0，并去遍历与j相连的城市也把他们变为0
依次遍历下去。
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.size()==0 || isConnected[0].size()==0) return 0;
        int Provinces=0;
        for(int i=0;i<isConnected.size();++i){
            for(int j=0;j<isConnected[0].size();++j){
                if(isConnected[i][j]){
                    ++Provinces;
                    dfs(isConnected,i,j);
                }
            }
        }
        return Provinces;
    }

    void dfs(vector<vector<int>>& isConnected, int i, int j){
        isConnected[i][j] =0;
        //递归遍历与j相连的城市
        for(int x=j,y=0;x<isConnected.size() && y<isConnected[0].size(); ++y){
            if(isConnected[x][y]){
                dfs(isConnected,x,y);
            }
        }
    }
};
