/*
因为只要求吃的开心的孩子最大人数
所以优先满足那些需求度低的孩子->给孩子需求度g排序
从最小的饼干来试，是否能让孩子满意->给饼干大小s排序
最后建立循环一一比对。
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        while(i<g.size() && j<s.size())
        {
            if(g[i]<=s[j]) i++;
            j++;
        }
        return i;
    }
};
