//Remove the nth node from the LL

//first count the length of LL.
//we don't need to reach the nth given node...but we need the (n-1)th node so that we can change the links.
//(n-1)th node will be :

// res=(cnt-n)
// delNode=temp->next;
// temp->next=temp->next->next;
// free(delNode);

int cnt=0, temp=head;
while(temp!=NULL){
  cnt++;
  temp=temp->next;
}
if(cnt==n){
  newHead=head->next;
  free(head);
  return newHead;
}
int res=cnt-n;
while(temp!=NULL){
  res--;
}
if(res==0)
  break;
temp=temp->next;
}
delNode=temp->next;
free(delNode);
temp->next=temp->next->next;
return head;
}

//T.C:O(len)+O(len-n) ~O(2*len) optimise
//S.C:O(1)

//optimal approach:
//take a pointer known as fast and move it 2 steps.
//then take a slow pointer and now move both slow and fast simultaneously by 1 step.
//stop when fast reaches the last node.
//now , slow is standing at the prev node.
fast=head;
for(int i=0;i<n;i++){
  fast=fast->next;
}
slow=head;
while(fast->next!=NULL){
  slow=slow->next;
  fast=fast->next;
}
if(fast==NULL){
  return head->next;
}
delNode=slow->next;
slow->next=slow->next->next;
free(delNode);
return head;

//leetcode solution:
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*fast=head;
        ListNode*slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL) return head->next;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode*delNode=slow->next;
        slow->next=slow->next->next;
        delete delNode;
        return head;
    }
};
//T.C:O(len)
//S.C:O(1)
