                               //Copy list with random pointer.

//<original, copy>

//1.Insert copy nodes in between.
//2.Connect random pointers.
//3.Connect next pointers.

class Solution {
public:
   void insertCopyInBetween(Node* head){
  Node* temp=head;
while(temp!=NULL){
  Node* nextElement=temp->next;
 Node*copyNode= new Node(temp->val);
  copyNode->next=nextElement;
  temp->next=copyNode;
  temp=nextElement;
}
   }
//copy nodes are inserted in between 
  void connectRandomPointers(Node* head){
    Node*temp=head;
while(temp!=NULL){
  Node*copyNode=temp->next;
  if(temp->random!=NULL)
  copyNode->random = temp->random->next;
   else 
    copyNode->random=NULL;
  temp=temp->next->next;
}
  }
//connected the random pointers.
  Node* getDeepCopyList(Node* head){
    Node*dummyNode= new Node(-1);
    Node* res=dummyNode;
    Node*temp=head;
while(temp!=NULL){
  res->next=temp->next;
  res=res->next;
  //disconnecting and going back to
  //initial state of the LL
  temp->next=temp->next->next;
  temp=temp->next;
}
return dummyNode->next;
  }


    Node* copyRandomList(Node* head) {
          insertCopyInBetween(head);
  connectRandomPointers(head);
  return getDeepCopyList(head);
    }
};

//T.C:O(n+n+n)=O(3n)
//S.C:O(n)   because question demands to create a new list..so cannot be omitted.
