/*
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // the solution should be like this,
        // if they intersect, they must share the last node,
        // we can count their lengths when we do the first visit of both

        // later, we can go a few more steps ahead for the longer node list, ...

        ListNode *pA, *pB;
        int lenA, lenB;
        pA = headA; pB = headB;

        if (!pA || !pB) return NULL;

        lenA = 0; lenB = 0;
        while(true) {
            ++lenA;
            if(!pA->next)
                break;
            pA = pA->next;
        }
        while(true) {
            ++lenB;
            if(!pB->next)
                break;
            pB = pB->next;
        }

        if(pA!=pB)
            return NULL;

        pA = headA; pB = headB;
        if(lenA > lenB) {
            for(int i=0; i<lenA-lenB; ++i)
                pA = pA->next;
        } else {
            for(int i=0; i<lenB-lenA; ++i)
                pB = pB->next;
        }

        while(true) {
            if(pA == pB)
                break;
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};
