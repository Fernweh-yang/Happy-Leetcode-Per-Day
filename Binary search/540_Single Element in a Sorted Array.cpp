/*
由于只有一个元素出现一次，其他都出现2次。所以数组元素个数必定是奇数个。
同理二分后，左右区间哪个是奇数的，哪个就是单个元素所在。
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]==nums[mid+1]){
                if((right-mid)%2==0){
                    left=mid+2;
                }
                else{
                    right=mid-1;
                }
            }
            else if(nums[mid]==nums[mid-1]){
                if((right-mid)%2==0){
                    right=mid-2;
                }
                else{
                    left=mid+1;
                }
            }
            else{ 
                return nums[mid];
            }
        }
        return nums[left];
    }
};
