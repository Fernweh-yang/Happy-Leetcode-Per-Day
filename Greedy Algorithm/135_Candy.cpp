/*思路：
先保证每个孩子都有一个糖果。
孩子数组从左往右，从右往左各遍历一遍
从左往右：右边的孩子如果比左边的孩子评分高，右边的孩子糖果数在左边孩子糖果数的基础上+1。
从右往左：左边的孩子如果比右边的孩子评分高&&左边孩子糖果数<=右边孩子糖果数，左边孩子糖果数在右边的基础上+1

贪心算法：局部最优解->总体最优解   这里就是两两之间最优解->所有人最优解
*/

//写法1
class Solution {
public:
    int candy(vector<int>& ratings) {
        int i = ratings.size();      //共有几个孩子
        int j = 0;   
        int output=0;               //输出总的糖果数
        int num[i];                 //各个孩子的糖果数
        
        //保证每个孩子有一个糖果
        for(;j<i;)
        {
            num[j]=1;
            j++;
        }    
        //从左往右遍历
        for(j=0;j<i-1;)
        {
            if(ratings[j] < ratings[j+1]) num[j+1]=num[j]+1;
            j++;
        }
        //从右往左遍历
        for(j=i-1;j>0;)
        {
            if(ratings[j]<ratings[j-1] && num[j]>=num[j-1] ) num[j-1]=num[j]+1;
            j--;
        }
        //计算总糖果数
        for(j=0;j<i;j++)
        {            
            output +=num[j];
        }
        return output;
    }
};

//写法2
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2 ) return size;
        
        vector<int> num(size,1);
        for(int i=1; i<size; ++i)
        {
            if(ratings[i] > ratings[i-1]) num[i]=num[i-1]+1;
        }           
        
        for(int i=size-1; i>0; --i)
        {
            if(ratings[i]<ratings[i-1])
                num[i-1]=max(num[i-1],num[i]+1);
        }
        
        return accumulate(num.begin(),num.end(),0);
    }
};
