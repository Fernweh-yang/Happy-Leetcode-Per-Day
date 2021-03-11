class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        count=0
        for i in range(1,len(prices)):
            benefit=prices[i]-prices[i-1]
            if benefit >0:
                count +=benefit
        return count
