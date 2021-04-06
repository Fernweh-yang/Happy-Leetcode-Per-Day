//关键字：回溯法backtracking ,二维数组，二维数组的初始化
/*
回溯的是:当前节点是否被访问过的状态。
因为不可重复使用，创建一个bool类型的visited数组，记录这个元素是否被用过了。
在继续向下递归前使当前节点为true，在递归回来后使其回溯状态为false，使得另一个可能步骤下仍然是全新的数组。
设定一个bool类型的find作为答案返回，若找完了所要找的字符串，则令其为true
*/
class Solution {
public:
    //主函数
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        bool find =false;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                //找到word的首字母才开始往下遍历
                if(board[i][j]==word[0]){
                    backtracking(board,word,visited,i,j,0,find);              
                }
            }  
        }
        return find;
    }
    vector<int> direction = {-1,0,1,0,-1};
    //辅函数
    void backtracking(vector<vector<char>>& board, string& word,vector<vector<bool>>& visited,int i, int j,int index,bool& find){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
        if(find || board[i][j] !=word[index] || visited[i][j] ) return;
        if(index == word.size()-1){
            find=true;
            return;
        }
        visited[i][j]=true;   //修改当前节点状态
        //递归子节点
        for(int k=0;k<4;++k){
            int x=i+direction[k];
            int y=j+direction[k+1];
            backtracking(board,word,visited,x,y,index+1,find);
        }
        visited[i][j]=false;  //回溯当前节点状态
    } 
};
