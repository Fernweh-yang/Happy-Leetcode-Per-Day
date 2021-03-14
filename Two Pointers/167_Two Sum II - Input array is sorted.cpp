/*
从两端向中间遍历
由于这是一个从小到大排列好的数组，又必定又答案，所以：
如果两指针之和>目标值，右指针的值太大，所以右指针左移一格。
如果两指针之和<目标值，左指针的值太效，所以左指针右移一格。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r=numbers.size()-1;
        while(l<r){
            if(numbers[r]+numbers[l]==target ) break;
            if(numbers[r]+numbers[l]<target) l++;
            else r--;
        }
        return vector<int> {l+1,r+1};
    }
};
