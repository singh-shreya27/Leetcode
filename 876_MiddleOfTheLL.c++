
//MIDDLE OF THE LL:TORTOISE AND HARE ALGORITHMN.

//brute force approach.
//middle node=(n/2+1)th node
//we need n , we are only given head of LL

temp=head, cnt=0;
while(temp!=NULL){
  cnt++;
  temp=temp->next;  
}
//this will count the number of nodes.->step1.T.C:O(n)
midNode=(cnt/2)+1;
//again place temp at head.
temp=head;
while(temp!=NULL)
{
  midNode=midNode-1;
  if(midNode==0)
    break;
  temp=temp->next;
}
return temp;
//step2: T.C:O(n/2)

//overall:T.C=O(n+n/2)
//S.C:O(1)
//optimise: because this is a two pass solution.


//OPTIMAL APPROACH:TORTOISE AND HARE ALGORITHMN.
//CONCEPT: slow and fast pointers.

//At first:take the first and slow pointers at the head.
//move both of them together but slow:1 step and fast:2 steps.
//we will stop when the fast pointer reaches the last node(odd length LL) and null (even length LL).
slow=head, fast=head;
while(fast!=NULL && fast->next!=NULL){
  slow=slow->next;
  fast=fast->next->next;
}
retuen slow;

//T.C:O(n/2)
//S.C:O(1)

//leetcode solution:
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
