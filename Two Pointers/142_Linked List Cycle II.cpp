/*
Floyd's Cycle Detection  快慢指针判环
一个快指针fast pointer每次移动2格
一个慢指针slow pointer每次移动1格
1、快指针很快遍历完链表，说明没有环，返回null
2、如果有环，那2指针必定会相遇。
   在两指针首次相遇时，将快指针指回链表头部，然后快指针慢指针都以每次1格的速度移动
   第二次相遇时必定在环的开端。
——————
证明为什么第二次相遇时必定在环的开端
环之前一共m格，环开始点到相遇点的举例为y格，环的总长度为x格。
则第一次相遇时：
慢指针移动了：m+y格
快指针移动了：m+y+nx格（快指针可能走了n圈环后，慢指针才进入环）
由于快指针速度是慢指针的2倍所以：2*(m+y)=m+y+nx  ->m=nx-y=(n-1)x+n-y
此时将快指针指回链表头部，然后快指针慢指针都以每次1格的速度移动
则快指针移动m格到达环开始点时，慢指针根据m=nx-y=(n-1)x+n-y，移动了n-1圈+n-y的距离。
而n-y+y正好走完环的一圈，即回到达环的开端。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        do{
            if(!fast || !fast->next) return NULL;
            fast= fast->next->next;
            slow= slow->next;
        } while(fast!=slow);
        fast = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next; 
        } 
        return fast;
    }
};
