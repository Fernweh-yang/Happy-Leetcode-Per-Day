#1.与CPP中一致的代码：
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        l,r=0,len(nums)-1
        aim=nums[r]
        while l<=r:
            mid=(r+l)//2
            if nums[mid]==nums[l]:
                if aim>nums[l]:
                    aim=nums[l]
                l+=1
            elif nums[mid] <=nums[r]:
                if aim>nums[mid]:
                    aim = nums[mid]
                r=mid-1
            else:
                if aim>nums[l]:
                    aim=nums[l]
                l=mid+1
        return aim
    
#更简洁的方法：
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]: left = mid + 1
            elif nums[mid] < nums[right]: right = mid
            else: right = right - 1 # key
        return nums[left]
