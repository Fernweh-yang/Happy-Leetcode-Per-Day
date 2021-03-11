/*
贪心算法：考虑局部（没一天），每一天如果是正收益就加，负收益就不交易->收益最大话。
因为这题相当于：一天一个股价当天买卖同价->预先知道每天股价的情况下，那每天的收益是固定->负收益的那天不加就得到最大收益。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count=0;
        for(int i=0; i< prices.size()-1;i++){
            int benefit = prices[i+1]-prices[i];
            count=count+max(benefit,0);
        }
        return count;   
    }
};
