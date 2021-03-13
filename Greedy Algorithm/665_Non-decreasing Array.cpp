/*
贪心算法：如果遇到[i]>[i+1]的情况，就要对其中一个改的尽量小，以免对后面造成连锁反应。
对此有2种情况：
1.[i-1]<=[i+1]，那直接将[i]改成[i+1]的值。
2.[i-1]也大于[i+1]，那只能使[i+1]变大了，使[i+1]=[i]。

记录改变次数。如果改变了2次，那就说明这个数组false.
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count=0;
        int size=nums.size()-1;
        
        for(int i =0; i<size && count<2;i++){
            while(nums[i]>nums[i+1]){
                if(i==0 ||nums[i-1]<=nums[i+1]){
                     nums[i]=nums[i+1];
                     count++;
                }
                else {
                    nums[i+1]=nums[i];
                    count++;
                }                
            }            
        }
        return count<=1;
    }
};
