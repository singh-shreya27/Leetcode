//Delete the middle of the LL.

//We have to reach the node before the middle node ..so that we can change the links .

//brute force:
//traverse the the node before the middle node: [n/2]th node.
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*temp=head;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;     //O(n)
        }
        int res=n/2;
        temp=head;
        while(temp!=NULL){
            res--;                  //O(n/2)
            if(res==0){
                ListNode*middle=temp->next;
                temp->next=temp->next->next;
                delete middle;
                break;
            }
            temp=temp->next;
        }
  return head;
    }
};
//T.C:O(3n/2) two pass solution
//S.C:O(1)

//optimal solution:
//one pass solution:
//tortoise and hare algorithmn.
//slight change in algo: skip 1 step of slow to make it reach one step before the middle node.

//leetcode solution:
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        //skip one step of slow:
        fast=fast->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow is pointing to prev of mid node
        //change the links
        ListNode*midNode=slow->next;
        slow->next=slow->next->next;
        delete midNode;
        return head;
    }
};
//T.C:O(n/2)
//S.C:O(1)


