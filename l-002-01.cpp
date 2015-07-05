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
        int val = 0, carry = 0;
        ListNode* res = new ListNode(0);
        ListNode* p = res;
        for(;l1||l2||carry;) {
            val = (l1? l1->val:0) + (l2? l2->val:0) + carry;
            p->val = val%10;
            carry = val/10;
            p->next = new ListNode(0);
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return res;
    }
};

WA
Input:
[0], [0]
Output:
[0,0]
Expected:
[0]

containing several mistakes!
without p = p->next
need to deal the first digit specially
