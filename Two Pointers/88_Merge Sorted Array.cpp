/*
因为nums1的空间是包含nums1和nums2有效元素之和的，而他们又按从低到高已排好序
所以只要从大到小，比较他们有效部分的大小m-1 > n-1 ?，哪个大就复制到nums1的末尾。
如果nums1的m个元素提前排完了，那就直接把nums2的n个元素中剩下还没排的直接依次插入nums1就好。
如果nums2的n个元素提前排完了，nums1由于本来就是从小到大排列，所以就此完工。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos=m-- + n-- -1;
        while(m>=0 && n>=0){
            nums1[pos--]= nums1[m] > nums2[n]? nums1[m--] : nums2[n--];
        }
        while(n>=0){
            nums1[pos--] = nums2[n--];
        }
    }
};
