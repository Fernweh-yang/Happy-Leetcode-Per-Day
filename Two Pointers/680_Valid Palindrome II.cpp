/*
左右指针分别从左边和右边向中间移动。
如果有一次不同，那就分别对（左+1==右指针）和（左指针==右-1指针）进行判断，如果再遇到一次不同就输出false。
其他情况则为true
*/
class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return ifPalindrome(s,i+1,j) || ifPalindrome(s,i,j-1);
        }
        return true;
    }

    bool ifPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
