//关键字：深度优先搜索DFS，Vector
/*
如果一个个元素的去查看是否能到达边界，复杂度太高。
不如从边界开始判断能到达哪个坐标，这个能到达的坐标就说明它能到达相应的大洋
创建2个2维bool类型的数组canReach来储存这些信息。
1个表示从Pacific走能到达此坐标,
1个表示从Atlantic走能到达此坐标。
最后2个都为真，就说明该坐标两大洋都能到达，是答案之一。
*/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()) return {};

        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        //一开始都设为False
        vector<vector<bool>> canReach_p(m,vector<bool>(n,false));
        vector<vector<bool>> canReach_a(m,vector<bool>(n,false));
        for(int i =0;i<m;++i){
            //能到达的某大洋，相应坐标的bool值就变为true
            dfs(heights,canReach_p,i,0);
            dfs(heights,canReach_a,i,n-1);
        }
        for(int i=0;i<n;++i){
            dfs(heights,canReach_p,0,i);
            dfs(heights,canReach_a,m-1,i);
        }
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;j++){
                if(canReach_a[i][j] && canReach_p[i][j]){
                    ans.push_back(vector<int>{i,j});
                }
            }
        }
        return ans;
    }
    vector<int> direction ={-1,0,1,0,-1};

    void dfs (vector<vector<int>>& heights, vector<vector<bool>>& canReach,int i, int j){
        if(canReach[i][j]) return;
        canReach[i][j] =true;
        int x,y;
        for(int k=0;k<4;++k){
            x=i+direction[k];
            y=j+direction[k+1];
            if(x>=0 && x<heights.size() &&
               y>=0 && y<heights[0].size() && heights[i][j]<= heights[x][y]){
                   dfs(heights,canReach,x,y);
               }
        }
    }
};
