/*
相当于给定一个非负整数，求解f(x)=x^2-a=0的解。
令左指针l=1，右指针r=a,中间值mid则为1+(a-1)/2
中间值的平方mid^2 若==a,则mid即所求值
若mid^2 >a,说明所求值落在左半区，调整右指针r
若mid^2 <a,说明所求值落在右半区，调整左指针l
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return x;    //如果是0，那就是他本身
        int l=1,r=x, mid,tmp;
        while(l<=r){
            mid=l+(r-l)/2;
            tmp=x/mid;                 //这里如果用mid*mid=x来做判断，mid*mid这个数值就可能特别大需要额外空间，所以用tmp来代表x/mid。 
            if(tmp==mid) return mid;   //这里的判断条件等价于mid*mid==x。且当x为奇数时会相等
            else if(tmp<mid) r=mid-1;  //这里的判断条件等价于mid*mid>x
            else l=mid+1;              //这里的判断条件等价于mid*mid<x
        }
        return r;                      //因为r指针是改动为mid-1，题目所求为较小的那个整数。当x为偶数时会来到这里，返回r
    }
};

/*牛顿迭代法：*/
int mySqrt(int a) {
  long x = a;
  while (x * x > a) {
      x = (x + a / x) / 2;
  }
  return x;
}
