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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val, carry = 0;
        val = (l1? l1->val:0) + (l2? l2->val:0) + carry; //val = l1->val + l2->val;
        ListNode* res = new ListNode(val%10);
        carry = val/10;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;

        ListNode* p = res;
        while(l1||l2||carry) {
            val = (l1? l1->val:0) + (l2? l2->val:0) + carry;
            p->next = new ListNode(val%10);
            carry = val/10;

            p = p->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return res;
    }
};
