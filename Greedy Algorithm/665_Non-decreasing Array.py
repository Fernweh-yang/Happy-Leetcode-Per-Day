class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        count=0
        for i in range(len(nums)-1):
            if nums[i] >nums[i+1] and count<2:
                if i==0 or nums[i-1]<=nums[i+1]:
                    nums[i]=nums[i+1]
                    count+=1
                else:
                    nums[i+1]=nums[i]
                    count+=1
                    
        return count <2
