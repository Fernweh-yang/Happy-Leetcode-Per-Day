//关键字：回溯法Backtracking,vector，排列
/*
回溯的是：排列到第i个数字时,i和其后面的数字交换的状态。
n个数字的所有排列组合：
1.从当前位置i=0开始，让他依次和他后面的所有数字进行交换。
  在交换完后就递归的从i+1=1开始和他后面的所有数字进行交换。
2.一直换到i=n-1，就说明每个位置都填上数字了，这个数组就是答案之一。
3.为了避免重复，再每次递归到底后都要将交换的元素换回来。
如此就穷举了所有的可能性。
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums,ans,0);   //1.从第一个数字开始和后面交换
        return ans;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& ans, int index){
        //2.如果index到n-1了，说明所有的数字都已填入，是为答案之一。
        if(index==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        //1.每个元素依次和后面的元素进行交换
        for(int i=index;i<nums.size();++i){
            swap(nums[i],nums[index]);          //循环的第一下一直是自己本身，递归会把这个自己一直传到最后index=n-1，就输出了
            backtracking(nums,ans,index+1);     //递归：交换i+1后的那些元素
            swap(nums[index],nums[i]);          //3.以免重复，每次递归完后，将数组变回原样。
        }

    }
};
