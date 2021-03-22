/*
由于数组之前是递增的，所以旋转后也还是总有一个区间是递增的
就不停的找递增区间，他最小值很容易找到，然后再对另一个区间进行二分。
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l=0,r=nums.size()-1;
        int min=nums[0];
        while(l<=r){            
            int mid=(l+r)/2;
            if(nums[mid]==nums[l]){
                if(min>=nums[l]) min=nums[l];
                ++l;
            }
            else if(nums[mid]<=nums[r]){
                if(min>=nums[mid]) min=nums[mid];
                r=mid-1;
            }
            else{
                if(min>nums[l]) min=nums[l];
                l=mid+1;
            }
        }
        return min;
    }
};
