/*
由于数组之前是递增的，所以旋转后也还是总有一个区间是递增的
就不停的找递增区间，他最小值很容易找到，然后再对另一个区间进行二分。
*/
/*
.py中还有种他人的写法，更简洁。
找到递增区间，锁定最小值出现在哪里，不用去判断min
如果mid>right说明：左区间是递增的，但最小的一定在右区间，所以之间另left移动到mid右边一格
如果mid<right说明：右区间是递增的，所以mid是右区间最小值，但不能缺点他就是整个数组最小值，所以另right移动到mid
如果mid=right说明：可能右区间值全相同[1,2,3,6,6,6],也可能右区间先减后增[6,6,6,1,6],所以另right左移一格去找上面2个情况。
由上可知，只有移动left可以确定最小值。所以最后返回left。
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
