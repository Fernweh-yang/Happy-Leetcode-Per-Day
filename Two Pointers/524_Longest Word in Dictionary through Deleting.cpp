/*
依次比较s和d中每个字符串。并用out记录当前满足条件的字符串
后面比较的字符串就和Out比：
1.如果比out小，就跳过。
2.如果比out大，就去判断是否满足条件，若满足成为新out
3.如果和out一样大，先判断是否满足条件，若满足再out从第一个字符开始比较大小，小的那个成为out.
*/
class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		string out = "";
		int size = 0;
		for (int i = 0; i<d.size(); i++) {
			if (d[i].size()>size) {
				for (int l = 0, r = 0; l<s.size(); l++) {
					if (s[l] == d[i][r]) r++;
					if (r == d[i].size()) {
						out = d[i];
						size = out.size();
						break;
					}
				}
			}
			else if (d[i].size() == size) {
				for (int l = 0, r = 0; l<s.size(); l++) {
					if (s[l] == d[i][r]) r++;
					if (r == d[i].size()) {
						for (int t = 0; t < d[i].size(); t++) {
							if (out[t] < d[i][t]) {
								break;
							}
                            else{
                                out = d[i];
								size = out.size();
                                break;
                            }
						}
						break;
					}
				}
			}
		}
		return out;
	}
};
