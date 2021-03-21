/*
因为数组是递增的
如果中间比右端小，说明右右区间是递增的
反之中间比右端大，则左区间是递增的
对递增的区间去判断target是否在递增区间内，若在则再次二分，若不在则对另一半区间进行二分。
特例：因为存在相同值，所以若中间值与左端一致，无法判断左右区间哪边递增，所以令左端+1.
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        
        while(l<=r){
            int mid=(r+l)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[l]) l++; //无法判断左右区间哪个是递增的[6,6,6,1,2]或[6,1,6,6,6],这时让左指针加1
            else if(nums[mid]<=nums[r]){  //此时右区间递增的
                if(nums[mid]<target && target<=nums[r]) l=mid+1;
                else r=mid-1;
            }
            else{//如果nums[mid]>nums[r]说明左边是递增的
                if(nums[l]<=target && target <nums[mid]) r=mid-1;
                else l=mid+1;
            }
        }
        return false;


    }
};
