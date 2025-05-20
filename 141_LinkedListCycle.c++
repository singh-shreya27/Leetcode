                //Linked List Cycle

//Detect a loop in the LL

//brute force approach
//we need to store the node(not elements..they might repeat)..so that we can know which node is visited again.
//using HASHING.
//map data structure

map <Node*, int> mpp;
temp=head; //don't tamper head
while(temp!=NULL){
  if(mpp.find(temp)==tick)
    return true;
  mpp[temp]=1;
  mpp.put({temp,1});
  temp=temp->next; 
}
return false;

//2 map operations: inserting in the map and checking in the map. 
//T.C:O(n*2logn) or O(n*2log1)
//S.C:O(n)   //optimise

//OPTIMAL APPROACH:
//Tortoise and the hare algorithmn.
//IMPORTANT:If at any point slow and fast pointers are standing at the same point : there was a loop.
//INTUITION: the difference between fast and slow is d ..and it is decreasing by 1 in every step..so eventually it will be 0 at a point in a loop.
slow=head, fast=head;
while(fast!=NULL && fast->next!=NULL){
  slow=slow->next;
  fast=fast->next->next;
    if(slow==fast){
      return true;
    }
}
return false;

//T.C:~O(n)
//S.C:O(1)
