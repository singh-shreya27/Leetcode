  //Odd and Even LL

//brute force approach:
//put up odd elements: T.C:O(n/2)

if(head==NULL || head->next==NULL){
  return head;
}
arr=[]
  temp=head;
while(temp!=NULL && temp->next!=NULL){
  arr.add(temp->data);
  temp=temp->next->next;  
}
  //if LL is of odd length ..we will miss the last element so
if(temp) {
  arr.add(temp->data);
}
//even elements //O(n/2)
temp=head->next;
while(temp!=NULL && temp->next!=NULL){
  arr.add(temp->data);
  temp=temp->next->next;  
}
if(temp) {
  arr.add(temp->data);
}

i=0, temp=head;
while(temp!=NULL){
  temp->data=arr[i];        //O(n)
  i++;
  temp=temp->next;
}
return head;
}

//T.C:O(2n)
//S.C:O(n)  using array to store elements
//optimise

//OPTIMAL APPROACH:
if(head==NULL || head->next==NULL){
  return head;
}
odd=head, even=head->next , evenHead=head->next;
  while(even!=NULL && even->next!=NULL){
    odd->next=odd->next->next;
    even->next=even->next->next;

    odd=odd->next;
    even=even->next->next;   //giving error in leetcode : chcek below code.
  }
odd->next=evenHead;
return head;

//T.C:O(n/2)*2=O(n)
//S.C:O(1)

//leetcode solution:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
  return head;
}
 ListNode* odd=head;
 ListNode* even=head->next ;
 ListNode* evenHead=head->next;
  while(even!=NULL && even->next!=NULL){
    odd->next=odd->next->next;
    even->next=even->next->next;

    odd=odd->next;
    even=even->next;  
  }
odd->next=evenHead;
return head;
    }
};
