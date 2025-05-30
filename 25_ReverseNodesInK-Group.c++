     //Reverse nodes in K-Group.

ListNode* reverseLL(ListNode* head){
    ListNode* temp=head;
    ListNode*prev=NULL;
    while(temp!=NULL){
        ListNode*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;

}
Node* getKthNode(Node* temp, int k){
 k-=1;
 // k: This is the position of the node we want to retrieve. It's 1-based, meaning k=1 returns the first node, 
  //k=2 returns the second node, and so on.
  //Since the function assumes k is 1-based (for human readability), it adjusts k to a 0-based index for easier manipulation inside the loop.
  while(temp!=NULL && k>0){
    k--;
    temp=temp->next;
  }
  return temp;
}
Node* kReverse(Node* head, int k){
 Node*temp=head;
Node*prev=NULL;
while(temp!=NULL){
  Node* kthNode=getKthNode(temp,k);
  if(kthNode==NULL){
    if(prevNode!=NULL)
    prevNode->next=temp;
    break;
  }
  Node* nextNode=kthNode->next; //remember the next node.
  kthNode->next=NULL;
  //now LL is separated
  reverseLL(temp);
  if(temp==head){
    head=kthNode;
  }
  else{
   prevNode->next=kthNode;
  }
   prevNode=temp;
   temp=nextNode;
} 
  return head;
}

//T.C:O(2n)
//S.C:O(1)
