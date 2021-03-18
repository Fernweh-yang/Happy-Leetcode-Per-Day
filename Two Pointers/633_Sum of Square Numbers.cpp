//和167思路类似
class Solution {
public:
    bool judgeSquareSum(int c) {
        int x=0,y=pow(c,0.5)+1;
        while(x<=y){
            auto sum=pow(x,2)+pow(y,2);
            if(sum == c) return true;
            else if (sum <c) x++;
            else y--;
        }
        return false;

    }
};
