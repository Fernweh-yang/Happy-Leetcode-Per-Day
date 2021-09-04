/*
题目：
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

思路：
每次只能爬1到2个台阶，说明i阶台阶可由i-1和i-2阶台阶到达。
所以i阶的方法数=i-1的方法数+i-2的方法数。-------> 典型的斐波那契数列问题。
由此得到该问题的状态转移方程：
n[i] = n[i-1] + n[i-2].

边界问题：
当i<2即n[1]。直接返回i就行。
当i=2，n[1]+n[0]=2,所以设置一n+1个值1位1的数组，然后从2开始往上计算。
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n<2) return n;
        vector<int> num(n+1,1);
        for(int i=2;i<=n;i++)
        {
            num[i]=num[i-1]+num[i-2];
        }
        return num[n];
    }
};