/*
因为第二个字符代表的是前面有几个比自己高的所以
身高最高的最容易确定相对位置->第二高的->最矮的

先按身高排序，一样身高的第二个字符小的排在前面。
然后创建一个新二维数组。
将一维数组从头一个个的插入新的二维数组

如果按最矮的开始排，向前没插入一个人，都和他的第二个数字有关系，而从最高开始就没影响。
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), sort_rule);
        vector<vector<int>> queue;

        for(int i=0; i<people.size();i++){
            queue.insert(queue.begin()+people[i][1],people[i]);
        }
        return queue;
    }
    static bool sort_rule(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1] < b[1];
        else return a[0]>b[0];
    }
};
