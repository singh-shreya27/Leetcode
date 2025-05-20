        //REVERSE A LL

//METHOD1:
//don't alter the head
//step1 : taking all the data and putting it into the stack.
//T.C:O(n)
temp=head ;
  stack<st>;
while(temp!=NULL){
  st.push(temp->data);
  temp=temp->next;
}

//step2: put back from stack
//T.C:O(n).
temp=head;
while(temp!=NULL){
  temp->data=st.top();
  st.pop();
  temp=temp->next;
}
//OVERALL:T.C:O(2n)
//S.C:O(n)  //optimise

//METHOD2:without using any external Data structure
//changine the links

//leetcode solution:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};
//T.C:O(n)
//S.C:O(1) :just changing the links

                           //RECURSIVE MATHOD:

