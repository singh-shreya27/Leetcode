                //Check if a LL is palindrome.

//Brute force solution:

//use stack(LIFO) to store the elements
//step1: store everything in stack ds. T.C:O(n)
stack st
temp=head;
while(temp!=NULL){
  st.push(temp->data);
  temp=temp->next;
}
//step2: compare :T.C:O(n)
temp=head;
while(temp!=NULL){
  if(temp->data!=st.top()) return false;
  temp=temp->next;
  st.pop();
}
return true;

//overall:T.C:O(2n)
//S.C:O(n)  optimise


//OPTIMAL APPROACH:
//Recognise the two halves-> find the middle of the LL.
//reverse the links of the second half.
//take two pointers : first and second.
//step1:     O(n/2)
slow=head, fast=head;
while(fast->next!=NULL && fast->next->next!=NULL){
  slow=slow->next;
  fast=fast->next->next;           
}
//step2:    O(n/2)
Node* newHead=reverse(slow->next);
//step3:     O(n/2)
first=head, second->newHead;
while(second!=NULL){
  if(first->data!=second->data){
    reverse(newHead);       //O(n/2)
    return false;
  }
  first=first->next;
  second=second->next;
}
reverse(newHead);   //IMPORTANT STEP.
return true;

//T.C:O(2n)
//S.C:O(1)


//Leetcode solution:
class Solution {
public:

 ListNode* reverseLL(ListNode*head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* newHead= reverseLL(head->next);
    ListNode*front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
 }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true; //empty LL or one element
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverseLL(slow->next);
        ListNode* first=head;
        ListNode* second= newHead;
        while(second!=NULL){
            if(first->val!=second->val){
                reverseLL(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLL(newHead);
        return true;
    }
};
