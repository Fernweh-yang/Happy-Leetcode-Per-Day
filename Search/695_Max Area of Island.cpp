//关键字：深度优先搜索DFS,栈,递归
/*
方法1：用栈来实现DFS
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();   //m：横坐标，n:纵坐标
        int current_area,area=0;
        int x,y;
        vector<int> direction={-1,0,1,0,-1};  //用于某一节点的上下左右搜索
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                //依次遍历每一个节点，只有有岛屿的，即值为1的才进行向下搜索
                if(grid[i][j]){
                    grid[i][j] = 0;
                    current_area=1;
                    stack<pair<int,int>> island;  //利用栈储存要上下左右搜索的岛屿坐标
                    island.push({i,j});
                    //只要还有岛屿要去搜索就循环下去
                    while(!island.empty()){
                        auto [r,c] = island.top();  //记录下当前要搜索的岛屿的坐标
                        island.pop();               //栈顶的岛屿即将开始搜索，所以可以把该坐标从栈中去除
                        //依次从上，右，下，左的顺序查看是否有其他相邻岛屿
                        for(int k=0;k<4;k++){
                            x=r+direction[k];
                            y=c+direction[k+1];
                            //可能会有多个[x,y]都是岛屿，他们都会压入栈，然后从栈顶开始另一轮的搜索。
                            if(x>=0 && x<m &&
                               y>=0 && y<n && grid[x][y]==1){
                                ++current_area;
                                island.push({x,y});  
                                grid[x][y]=0;
                            }
                        }
                    }
                    area=max(current_area,area);
                }
            }
        }
        return area;
    }
};

/*
方法2：用递归来实现DFS
- 需要分主函数和辅函数
    1.主函数：用于遍历所有的搜索位置，判断是否可以开始搜索，如果可以即在辅函数进行搜索
    2.辅函数：负责深度优先搜索的递归调用
- 辅函数内递归搜索时，要注意边界条件设定，两种写法：
    1.第一种：先判定是否越界，只有在合法的情况下才进行下一步搜索(判断放在递归调用之前)
    2.第二种: 先进行下一步搜索，搜索开始时再判断是否合法(判断放在辅函数第一行)
*/
//主函数写法一致：
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int max_area =0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]){
                    max_area=max(max_area,dfs(grid,i,j));
                }
            }
        }
        return max_area;
    }
//第一种辅函数写法：
    vector<int> direction{-1,0,1,0,-1};
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(grid[i][j]==0) return 0;
        grid[i][j]=0;
        int x,y,area=1;
        for(int k=0;k<4;++k){
            x=i+direction[k];
            y=j+direction[k+1];
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()){
                area += dfs(grid,x,y);
            }
        }
        return area;
    }
};
//第二种辅函数写法：
int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || 
           j<0 || j>=grid[0].size() || grid[i][j]==0) return 0;
        grid[i][j]=0;
        return 1+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i+1,j)+dfs(grid,i,j-1);        
}
