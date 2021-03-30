/*
方法一：桶排序
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //第一步：为每个值建立一个桶，桶内记录出现的次数
        unordered_map<int,int> counts;  //利用无序容器记录每个数出现的次数,第一个int是值，第二个int是该值出现的次数
        int max_count =0;       //记录最大次数
        for(const int & num:nums){
            max_count = max(max_count,++counts[num]);
        }
        
        //第二步：建立一个新桶，以出现的次数为下标，将数字计入
        //因为可能有多个数字出现的次数相同，所以用二维数组
        vector<vector<int>> buckets(max_count+1); //因为下标从0开始，所以是最大次数+1
        for(const auto & p:counts){
            buckets[p.second].push_back(p.first);
        }
        
        //第三步：对新桶进行排序,只要排前K个大进行，并输出他们
        //因为只有唯一可能的k个解，所以不用额外排序比较大小
        vector<int> ans;  //记录要输出的那k个数字
        for(int i=max_count; i>=0 && ans.size()<k; --i){
            for(const int & num:buckets[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    break;
                }
            }
        }
        return ans;
    }
};
/*
方法二：堆排序
*/
class Solution {
public:
    // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
    //给priority_queue写的比较规则，这里建立小顶堆即要降序的数组。
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //用哈希表记录每个元素出现的次数
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        //STL的优先队列priority_queue底层是用堆实现的
        //各参数分别为：<储存的元素类型,储存元素的容器的类型，比较类型>
        //decltype区别与auto：需要某个表达式的返回值类型而又不想实际执行它时用decltype。
        //用q记录前k个最大的数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {    //一旦k里的元素到了k个，就要比较堆顶元素的大小
                if (q.top().second < count) {       //堆顶即数组最后那个元素。他出现的次数如果小于之后遍历的那些元素
                    q.pop();                        //那就说明现在堆顶的这个数字出现的次数不在前k个，所以移除顶部元素
                    q.emplace(num, count);          //并将现在遍历到的这个元素送入优先队列q，优先队列会自动帮我们排序。
                }
            } else {        //如果没到k个，就直接把元素输入k。
                q.emplace(num, count);
            }
        }
        
        //用ret输出
        vector<int> ret;
        //q若不为空，将优先队列q的元素输入到数组ret里去
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
