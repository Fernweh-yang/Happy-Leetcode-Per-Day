//关键词:双向广度优先搜索bfs, 回溯法Backtracking,哈希表（set,map)构建映射,size_t
本解超时，还需要进一步优化。
/*
思路：
将每个单词想象成一个点，每2个单词若可以通过换一个字母来互相转换，他们之间有一条双向边，如此形成一张图。
所以首先用bfs建立图。
然后以beginword为起点运用回溯法一直找到enword.
算法实现：
1.首先建立一个单词映射dict，把wordlist中所有的单词都包含其中，若endword不在其中则无解返回空。
2.设立数组q1，q2,q，记录从起点/终点开始bfs搜索后所经过的路径(层数)。
3.再建立一个单词映射next，运用bfs将映射中的单词两两匹配，检查他们2是否可以通过只换一个字母来互相转换，若是建立双向边。
4.在bfs中如果两边遍历到同一节点了，说明这条路遍历完了，所有相连节点都已建立双向边。
4.最后用回溯法重建所有可能路径
5.由于本题起点和终点固定，所以用从起点和终点同时开始双向BFS，相比单向bfs大约缩小一半时间
*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        //建立一个单词映射dict，把wordList所有单词包含其中
        unordered_set<string> dict;
        for(const auto& w: wordList){
            dict.insert(w);
        }
        //如果endWord不在wordList中，说明没有路径可到达，直接返回空数组
        if(!dict.count(endWord)){
            return ans;
        }

        dict.erase(beginWord);  //移除起点
        dict.erase(endWord);    //移除终点
        unordered_set<string> q1{beginWord};  //记录从起点开始BFS的路径(层数)
        unordered_set<string> q2{endWord};    //记录从终点开始BFS的路径
        unordered_map<string,vector<string>> next;  //建立一个新的单词映射，搭建可只换一个字母就能互相转换的2个单词间的双向边。vector<string>存放着路径
        bool reversed =false, found =false;         //reversed为false时是从起点开始bfs,为true时是从终点开始bfs

        //用bfs来建立双向边
        while(!q1.empty()){
            unordered_set<string> q; //记录进行BFS的路径，用于之后判断应该从起点/终点开始进行BFS
            for(const auto& w: q1){
                string s=w;
                //依次从起点单词的第一位字符到最后一位，尝试更换字符，此后s代表的单词在变w不变
                for(size_t i=0;i<s.size();i++){
                    char ch = s[i];
                    //开始更换字符，因为本题规定都是小写字母，所以从a开始26个。
                    for(int j=0; j<26;++j){
                        s[i]=j+'a';         //从a开始更换一直换到z
                        if(q2.count(s)){    //如果更换字母后，起点单词变成了终点单词
                            reversed ? next[s].push_back(w) : next[w].push_back(s); //建立双向边
                            found =true;
                        }
                        if(dict.count(s)){  //如果更换字母后，起点单词变成了单词列表中的某一个单词
                            reversed ? next[s].push_back(w) : next[w].push_back(s); //建立双向边
                            q.insert(s);    //记录路径
                        }
                    }
                    s[i]=ch;
                }
            }
            if(found) break;
            //如果没找到，在第一个映射中删除那些路径
            for(const auto& w:q){
                dict.erase(w);
            }
            //由于是从两头分别进行广度优先搜索，所以每次只延展当前层节点数最少的那一端；
            if(q.size()<=q2.size()){
                q1=q;
            }else{
                reversed=!reversed;
                q1=q2;
                q2=q;
            }
        }
        if(found){
            vector<string> path ={beginWord};
            backtracking(beginWord,endWord,next,path,ans);
        }
        return ans;
    }

    //用回溯法来找到所有的路径
    void backtracking(const string& src, const string& dst, unordered_map<string,vector<string>>& next,
        vector<string>& path, vector<vector<string>>& ans){
            if(src == dst){
                ans.push_back(path);
                return;
            }
            for(const auto& s:next[src]){
                path.push_back(s);  //插入相连节点
                backtracking(s,dst,next,path,ans);
                path.pop_back();    //删除最后一个元素，(回溯)
            }
        }
};
