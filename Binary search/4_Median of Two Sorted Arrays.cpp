/*
以O(logN)的时间复杂度，返回2个数组所有元素的中位数。所以不能直接合并(时间O(n))。
本题其实是在2个递增数组里寻找第K个元素：
  - 如果两数组元素个数合n为奇数->寻找第n/2+1个元素
  - 如果两数组元素个数合n为偶数->寻找第n/2和n/2+1个元素之和除以2。
所以单独写一个找第某个元素的的函数就好。

基本思路：
-比较两个数组的第k/2个元素，这2个哪个小，就可以排除相应数组的k/2个元素
  因为他们都必定比第k个元素小（比如数组1的第k/2元素小于数组2的第k/2个元素，那么数组1的第k/2个元素至多只可能比k-1个元素大了）
  在去除这些已经确定的元素时，要注意让k减去已确定元素的个数。然后在新的数组里去找第k个元素。
-如此不断循环，到k=1，就输出两数组当前第一个元素。
  因为是第一个吗- -，所以肯定是当前数组中最小的那个。。。
- 如果一个数组跑完了 或者 一个数组直接是空数组，那就可以直接输出另一个数组的第k个元素
- 以上所说的第k个，都从下标为1计算。代码中要注意-1。
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalsize=nums1.size()+nums2.size();
        if(totalsize % 2 ==1) return getKeys(nums1,nums2,totalsize/2+1);  //如果两数组元素个数合n为奇数->寻找第n/2+1个元素
        else return (getKeys(nums1,nums2,totalsize/2)+getKeys(nums1,nums2,totalsize/2+1))/2.0;   //如果两数组元素个数合n为偶数->寻找第n/2和n/2+1个元素之和除以2。
        }
private:
    //单独写一个找第某个元素的的函数
    double getKeys(vector<int>& nums1, vector<int>& nums2, int k){
        int m=nums1.size(),n=nums2.size();
        //用index来确定，删除元素后，从哪里开始找第k个元素
        int index1=0,index2=0;
        while(true){
            if(m==index1) return nums2[index2+k-1];
            if(n==index2) return nums1[index1+k-1];
            if(k==1) return min(nums1[index1],nums2[index2]);

            int no1=min(index1+k/2-1,m-1);    //防止数组越界
            int no2=min(index2+k/2-1,n-1);
            int point1 = nums1[no1];
            int point2 = nums2[no2];
            if(point1<=point2){
                k-= no1-index1+1;
                index1 = no1+1;
            }
            else{
                k-= no2-index2+1;
                index2 = no2+1;
            }
        }
    }
};
