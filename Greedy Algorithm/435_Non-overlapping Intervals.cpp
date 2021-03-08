/*
选择的区间结尾越小，余留给其它区间的空间就越大 -> 贪心算法: 优先保留结尾较小，且不相交的区间。
->找到重叠的去除他。

1：当各区间以开头从小到大排列时
第二个区间的开头一定要<第一个区间的结尾，他才重叠，要去除一个。
去除max(第一个区间的结尾，第二个区间的结尾)那一个区间。
或  
2：当各区间以结尾从小到大排列时
第二个区间的开头一定要<第一个区间的结尾，他才重叠，要被去除。
如果只判断要去除几个就不用考虑：去除min(第一个区间的开头，第二个区间的开头)那一个区间。

所以显然本题按第二种排列更有利。
*/

方法一:
//由于sort，对相同值的排序具有不确定性，所以要加一个判断去除哪一个
//对数组vector<vector<int>> intervals = {{1,100},{11,22},{1,11},{2,12}} 排序
//可能会[1,100]在前，也可能[1,11]在前。
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        
        //按开头排序
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int num = 0; 
        int size = intervals.size();
        int comp = intervals[0][1];
        for(int i=1; i<size;i++)
        {   //第一个区间的结尾一定要>第二个区间的开头  -> 重叠->num++
            if(comp > intervals[i][0]) 
            {
                num+=1;
                comp = min(intervals[i][1],comp);  //去除max(第一个区间的结尾，第二个区间的结尾)那一个区间。
            }
            else comp = intervals[i][1];
        }
        return num;
    }
};

方法二：
//不需要取进行判断去除哪一个
//对数组vector<vector<int>> intervals = { {1,2},{3,10},{x,14},{2,10} };
//因为排列成[1,2],[3,10],[2,10],[x,14]  ->[2,10]被清除     如果x > 10,则不清除
//或者排列成[1,2],[2,10],[3,10],[x,14]  ->[3,10]被清除     如果x < 10,则不论上下哪种情况都要清除一个。
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int num = 0; 
        int size = intervals.size();
        int comp = intervals[0][1];
        for(int i=1; i<size;i++)
        {
            if(comp > intervals[i][0]) num+=1;
            else comp = intervals[i][1];
        }
        return num;
    }
};
