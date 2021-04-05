//关键字：回溯法backtracking,vector,组合
/*
相比于dfs改变了数据状态不管了，回溯法改变后要改变回去。
而组合问题不像排列Permutations问题一样有个数组在那，给人改变再该回去。
所以我们自己创造一个k大小的数组comb。

之后的辅函数思想和Permutations一致：
1.从1开始填入数组comb，然后递归1之后的数字插入数组
2.因为不能有重复，所以都是从插入的那个数字后面的数字来选择填入。
如果插入的个数count等于了k，就把comb作为答案之一插入ans数组。
3.递归完成后将状态回到最开始，即count--。
如此反复从2一直到n开始填入数组。
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k,0);
        int count=0;
        backtracking(ans,comb,count,1,n,k);
        return ans;
    }

    void backtracking(vector<vector<int>>& ans,vector<int>& comb,int count,int pos, int n, int k){
        if(count==k){
            ans.push_back(comb);
            return;
        }
        for(int i=pos;i<=n;i++){
            comb[count++]=i;      //1.修改当前节点状态
            backtracking(ans,comb,count,i+1,n,k); //2.从插入数字的后面递归选择数字插入，以避免重复
            --count;              //3.回溯当前节点状态
        }
    }
};
