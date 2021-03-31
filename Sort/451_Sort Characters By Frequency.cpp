/*
运用桶排序。
*/
class Solution {
public:
    string frequencySort(string s) {
        //用哈希表记录每个字符出现的次数
        unordered_map<char,int> counts;
        int max_count = 0 ;
        for(const char & t: s){
            max_count = max(max_count,++counts[t]);
        }
        
        //建立桶，按出现次数的大小作为下标，记录字符
        vector<vector<char>> buckets(max_count+1);
        for(const auto & j:counts){
            buckets[j.second].push_back(j.first);
        }
        
        //从桶的末端输出所有字符
        string out;
        for(int i =max_count;i>=1;--i){
            for(const auto & p:buckets[i]){
                for(int j=0;j<i;++j)
                    out.push_back(p);
            }
        }
        return out;
    }
};
