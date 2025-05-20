        //starting node in a loop of a LL.
mao<Node*, int> mpp;
temp=head;
while(temp!=NULL){
   if(mpp.find(temp)==tick){
     return temp;//starting point
   }
  mpp[temp]=1;
  temp=temp->next;
}
return NULL;

//T.C:O(2n*logn) 2 operations in map  
//S.C:O(n)   optimise

//OPTIMAL APPROACH: TORTOISE AND HARE ALGO.
//step1: detect a loop
//step2:find starting point.
  //first find the collision point and then start slow from head and fast from the collision point .
//Now move both simultaneously only 1 step..fast also only 1 step.
//Now, slow and fast pointers will collide again ..this will be the starting point of the loop.

//step1:
slow=head, fast=head;
while(fast!=NULL && fast->next!=NULL){
  slow=slow->next;
  fast=fast->next->next;
  if(slow==fast){
      //step 2:
    //move them simultaneoulsy one step till they collide.
    slow=head;
    while(slow!=fast){
      slow=slow->next;
      fast=fast->next;  //one step
    }
    return slow; //starting point
  } 
}
return NULL;

//leetcode solution:
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
     return NULL;
    }
};

