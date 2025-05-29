   //ADD TWO NUMBERS.


func(head1, head2){
  t1=head1, h2=head2;
  dummyNode= new Node(-1);
  curr= dummyNode;
 carry=0;
  while(t1!=NULL || t2!=NULL){
    sum=carry;
    if(t1) 
      sum=sum+t1->data;
    if(t2)
      sum=sum+t2->data;

    newNode= new Node(sum%10);
    carry= sum/10;
    curr->next= new Node;
    curr=curr->next;
    if(t1)
      t1=t1->next;
    if(t2)
      t2=t2->next;
  }
  if(carry) {
    newNode= new Node(carry);
    curr->next=newNode;
  }
  return dummyNode->next;
}
//T.C:O(max(n1,n2)
//S.C:O(max(n1,n2))

//WHENEVER WE NEED TO CREATE A NEW LIST WHERE YOU STORE THE RESULT OR SOMETHING :
// ALWAYS PREFER TO USE THE CONCEPT OF DUMMY NODE.

//leetcode solution:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead= new ListNode(-1);
        ListNode* curr= dummyHead;
        ListNode* temp1= l1;
        ListNode* temp2= l2;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum=carry;
            if(temp1) sum+=temp1->val;
            if(temp2) sum+=temp2->val;
            ListNode* newNode = new ListNode(sum%10);
            carry=sum/10;

            curr->next=newNode;
            curr=curr->next;

            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }
        if(carry) {
            ListNode* newNode= new ListNode(carry);
            curr->next= newNode;
        }
        return dummyHead->next;

    }
};
