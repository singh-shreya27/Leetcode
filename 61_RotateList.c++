          //Rotate a linked list.

ListNode* findNthNode(ListNode* temp, int k){
  int cnt=1;
  while(temp!=NULL){
    if(cnt==k) return temp;
    cnt++;
    temp=temp->next;
  }
  return temp;
}

ListNode* rotateRight(ListNode* head, int k){
  if(head==NULL || k==0) return head;
  int len=1;
ListNode*tail=head;
while(tail->next!=NULL){
  len++;
  tail=tail->next;
}
if(k%len==0) return head; //edge case
 k=k%len;
  //attach the tail to the head
tail->next=head;
ListNode* newLastNode= findNthNode(head,len-k);
  head= newLastNode->next;
  newLastNode->next= NULL;
return head;

}

//T.C:O(2n)
//S.C:O(1)

