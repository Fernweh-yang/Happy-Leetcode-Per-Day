class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        i=0
        j=pow(c,0.5)+1
        j=int(j)
        while i<=j:
            sum=pow(i,2)+pow(j,2)
            if sum == c:
                return True
            elif sum >c:
                j-=1
            elif sum<c:
                i+=1
        return False
