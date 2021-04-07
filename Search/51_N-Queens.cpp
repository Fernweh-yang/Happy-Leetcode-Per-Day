//关键字：回溯法backtracking,vector
/*
回溯的是：棋盘上Q放置的位置，和他所能攻击到的位置。
规则：
皇后可以不限格数直线和斜线攻击。
思路：
从棋盘第一格开始尝试放置皇后，然后在将其斜线和直线之外的位置尝试放置其他皇后。
如此类推。
细节：
直线->横行，每行遍历时只放一个Q，一旦放置就进入下一行去尝试放置
直线->竖行，建立一个n个值得bool类型一维数组column，每一个下标对应一列，初始值都为false，一旦该列放置了Q则转为true
斜线->左斜线，一共有2n-1条对角线，左下角那条为第0条，右上角那条为第2n-2条。如竖行那样为其设立一个2n-1个值的bool类型一维数组ldiag
斜线->又斜线，同样有2n-1条对角线，左上角那条为第0条，右下角那条为第2n-2条。如竖行那样为其设立一个2n-1个值的bool类型一维数组rdiag

对于[i,j]位置放置Q，则它对应的左斜线为第[n-1-i+j]条，右斜线为第[i+j]条：
原理是，
同一左斜线上的横纵坐标[i,j]：i-j是固定值
同以右斜线上的横纵坐标[i,j]: i+j是固定值
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> column(n,false);
        vector<bool> ldiag(2*n-1,false),rdiag(2*n-1,false);
        vector<string> board(n,string(n,'.'));
        backtracking(0,n,ans,column,ldiag,rdiag,board);
        return ans;
    }
    void backtracking(int row,int n, vector<vector<string>>& ans, vector<bool>& column,vector<bool>& ldiag, vector<bool>& rdiag,vector<string>& board){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;++i){
            if(column[i] || ldiag[n-1-row+i] || rdiag[row+i+1]){
                continue;
            }
            //修改当前节点
            board[row][i] = 'Q';
            column[i]=ldiag[n-1-row+i]=rdiag[row+i+1]=true;
            //递归子节点
            backtracking(row+1,n,ans,column,ldiag,rdiag,board);
            //回溯当前节点
            board[row][i] = '.';
            column[i]=ldiag[n-1-row+i]=rdiag[row+i+1]=false;
        }
    }
};
