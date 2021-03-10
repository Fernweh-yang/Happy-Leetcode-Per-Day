/*
第一段别人写的，思路是一样的，但更简洁更美丽
第二段代码超出时间限制, 可能是代码里有问题。
*/
//第一段
class Solution {
public:
    vector<int> partitionLabels(string S) {
        //用end 和 start来划分现在的一个区间
        int map[26], length = S.size(), end = 0, start = 0;
        vector<int> ans;
        
        //记录字符串中每个字母最后出现的位置
        for(int i = 0;i < length;i++){map[S[i]-'a'] = i;}

        //遍历字符串
        for(int i = 0;i < length;i++)
        {
            end = max(end, map[S[i]-'a']); //贪心策略：每次刷新到最小的但是要全部包含字母的位置
            if(i == end) //如果指针i找到了end的话，就代表这个区间已经搜索完毕
            {
                ans.push_back(end-start+1);
                start = end + 1;
            }
        }
        return ans;
    }
};



//第二段:
class Solution {
public:

    vector<int> partitionLabels(string S) {
        vector<int> values;
        if(S.size()==1){
            values = {1};
            return values;
        }
        auto it = values.end();
        int num;
        for(int i=0;i<S.size();){
            int first_space = last_appear(S,i);
            int last_space = extra_space(S,i+1,first_space);
            num = last_space + 1;
            it = values.insert(it,num);
            i=last_space+1;
        }
        return values;
    }

    //某一字符comp最后出现位置->形成1个区间
    int last_appear(string S, int comp)
    {   int i = S.size()-1;
        for(;i>=0;i--){
            if(comp == S[i]) return i;
        }
        return 0;
    }

    //判断小区间S[start]->S[end]内是否会形成一个额外空间,若是则一直找到最后一个额外空间。
    int extra_space(string S,int start,int end){
        int prev=end;
        for(int i =start;i<end;i++)
        {           
            if(last_appear(S,i)>prev) prev=last_appear(S,i);
        }
        if(prev == end) return prev;
        else
        {
            extra_space(S,end,prev);
        }
        return 0;
    }
};
