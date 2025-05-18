class Solution {
public:
    void deleteNode(ListNode* node) {
     node->val=node->next->val;
     node->next=node->next->next;
    }
};

//we don't have access to previous ..so we make the node equal to the next node..then we have this node as the previous node for the next node..so we deleted that easily.
