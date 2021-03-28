/*
快速选择：运用的快速排序的思想。
只是每次基准元素切分后，比较下基准元素当前位置，如果是目标，就返回他
如果比目标值大，就只在左区间做递归
如果比目标值小，就只在右区间左递归
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1,target=nums.size()-k;
        while(l<r){
            int key=quick_select(nums,l,r);
            if(key==target) return nums[key];
            if(key<target) l=key+1;
            else r=key-1;
        }
        return nums[l];
    }

    int quick_select(vector<int>& nums, int l, int r){
        int i=l+1,j=r;
        while(true){
            while(i<r && nums[i]<=nums[l]){
                ++i;
            }
            while(j>l && nums[j]>=nums[l]){
                --j;
            }
            if(i>=j) break;
            swap(nums[i],nums[j]);
        }
        swap(nums[l],nums[j]);
        return j;
    }
};
