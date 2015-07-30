#include <iostream>
#include <unordered_map>

using namespace std;


//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *n=dummy, *o=head;
        unordered_map< RandomListNode*, RandomListNode* > copyTable;
        while(o != NULL) {
            n->next = new RandomListNode(o->label);
            n = n->next;
            copyTable[o] = n;

            o = o->next;
        }
        o = head; n = dummy->next;
        while(o != NULL) {
            if(o->random == NULL)
                n->random = NULL;
            else
                n->random = copyTable[o->random];

            n = n->next;
            o = o->next;
        }
        return dummy->next;
    }
};

int main() {

    return 0;
}
