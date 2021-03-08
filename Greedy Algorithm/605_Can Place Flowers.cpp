/*
方法一：从左往右遍历，如果连续三个0则可以种花。《
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size =flowerbed.size();
        int comp = flowerbed[0];
        int num=0;  //记录可以种几朵花
        int i=1;
        int end = size -1;
        //单独判断开头和结尾
        if(size==2){//可能数组只有2个值
            if (comp==0 && flowerbed[1]==0) num++;
        }
        else if(size>2){
            if (comp==0 && flowerbed[1]==0) 
            {
                num++;
                i=2;
                comp = flowerbed[1];
            }
            if (flowerbed[size-1]==0 && flowerbed[size-2]==0) 
            {
                num++;
                end--;
            }
        }
        else //可能数组只有1个值或空数组
        {
            if(comp==0) num++;
        }
        //判断中间部分
        for(; i < end; )
        {   
            //只有连续3个0才可能种一朵花
            if(flowerbed[i]==0 && flowerbed[i+1]==0 &&comp==0)
            {
                num++;                   
                comp = flowerbed[i+1];   
                i+=2;                
            }
            else
            {
                comp=flowerbed[i];
                i++;
            }        
        }
        if(n>num) return false;
        else return true;
    }
};

/*
方法二：从左往右遍历，如果是1就往右跳2格（跳过的那格必定为0），
如果是0判断下一格是否为0，若=0，则可以种花n-=1，并向右跳2格。
若下一格是1，则向右跳3格。最后判断是否n<=0。若是则可以种n朵花
*/
但在[0,1,0,1,0,1,0,0] 1和 [0] 1 都会出现Runtime Error 的问题。尚未知原因

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for(int i=0;i<size && n>0;)
        {
            if(flowerbed[i]==1) i+=2;
            else if(flowerbed[i+1]==0 || i==size-1) 
                {
                    n--;
                    i+=2;
                }
            else i+=3;            
        }
        return n<=0;
    }
};
