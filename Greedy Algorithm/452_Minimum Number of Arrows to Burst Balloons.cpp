/*
每一箭要尽可能多的射中气球 -> 求各气球的重叠数
先将气球按右边的坐标来依次排序。
如果第二个左边的坐标小于第一个右边的坐标，就能1箭中2。
而第三个左边的坐标要小于第一个右边的坐标，才能一箭中3。
如果左边的坐标大于第一个右边的坐标，就要多射一箭。并将第三个气球作为新的第一个气球来参考。

*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        if(points.empty()) return 0;
        if(points.size()==1) return 1;
        int prev = points[0][1];
        int conts= 1;
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>prev) 
            {
                conts++;
                prev = points[i][1];                               
            }
        }
        return conts;
    }
};
