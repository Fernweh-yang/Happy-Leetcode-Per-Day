/*
题目：
偷窃沿街的房屋，但不能在同一晚上偷窃相邻的2户人家。
给定一个代表每个房屋存放金额的非负数组，求一晚上最多能偷多少钱？
比如：输入[1,2,3,1] 输出4

思路：
第一步：定义子问题
    从k个房子中能偷到的最大金额f(k)是多少?
第二步：子问题之间的递推关系
    偷k个房子，有2种情况：
        1.最后一个房间不偷,偷前k-1个，从而变成了问题f(k-1)
        2.最后第二个房间不偷，偷最后1个+前k-2个，从而变成了问题f(k-2)
    显然要取上述2种情况中金额高的那个:
        f(k)=max[H(k)+f(k-2),f(k-1)]     //H(k)是第k个房间的钱，
    边界条件：
        1.如果k=0没房子，所以f(0)=0
        2.如果k=1，只有1房子，所以f(1)=H(1)
第三步：DP数组自下而上计算
第四步：空间优化
*/
//自己代码：
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        if(n==0){
            return 0;
        }
        if(n==1){
            return dp[1];
        } 
        for(int i=2; i<=n; i++){
            if(dp[i-1]>(dp[i-2]+nums[i-1]))
                dp[i] = dp[i-1];
            else
                dp[i] = dp[i-2]+nums[i-1];
        }
        return dp[n];
    }
};

//示例代码：
int rob(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    // 子问题：
    // f(k) = 偷 [0..k) 房间中的最大金额

    // f(0) = 0
    // f(1) = nums[0]
    // f(k) = max{ rob(k-1), nums[k-1] + rob(k-2) }

    int N = nums.size();
    vector<int> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int k = 2; k <= N; k++) {
        dp[k] = max(dp[k-1], nums[k-1] + dp[k-2]);
    }
    return dp[N];
}
//空间优化：
int rob(vector<int>& nums) {
    int prev = 0;
    int curr = 0;

    // 每次循环，计算“偷到当前房子为止的最大金额”
    for (int i : nums) {
        // 循环开始时，curr 表示 dp[k-1]，prev 表示 dp[k-2]
        // dp[k] = max{ dp[k-1], dp[k-2] + i }
        int temp = max(curr, prev + i);
        prev = curr;
        curr = temp;
        // 循环结束时，curr 表示 dp[k]，prev 表示 dp[k-1]
    }

    return curr;
}