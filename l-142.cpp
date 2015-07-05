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
        if(head == NULL)
            return NULL;
        ListNode *a1=head, *a2=head;
        /*要注意，当我们要声明多个指针变量时，必须在每个指针变量名前加上*，例如：
        int *p1, *p2, p3; //p1 p2是指向整型变量的指针变量，而p3是int*/
        do {
            if(!(a1->next) || !(a2->next) || !(a2->next->next) ) return NULL;
            a1 = a1->next;
            a2 = a2->next->next;
        } while(a1 != a2);

        a1 = head;
        do {
            a1 = a1->next;
            a2 = a2->next;
        } while(a1 != a2);
        return a1;
    }
};


Input:
[1,2], tail connects to node index 0
Output:
tail connects to node index 1
Expected:
tail connects to node index 0

Problem!
the 2nd loop should have a different structure!
not do { } while()
should be
while() { }
