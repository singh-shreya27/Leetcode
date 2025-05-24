            //SORT A LIST:

//brute force solution:
//take all the elements ..put it in array, sort them then put them all back to the LL.

function(head){
  arr[];
temp=head;
while(temp!=NULL){
  arr.add(temp->data);   //O(n)
  temp=temp->next;
}
  sort(arr);     //merge or quick sort O(nlogn)
  i=0; temp=head;
  while(temp!=NULL){
    temp->data=arr[i];           //O(n)
    i=i+1, temp=temp->next;
}
return head;

//T.C:O(2n+nlogn)
//S.C:O(n)  //optimise

//code of merge sort:
// mergeSort(arr, low, high){
//   if(low==high)  //single element
//     return ;
//   mid=(low+high)/2;

//   mergeSort(arr,low,mid);
//   mergeSort(arr,mid+1,high);

//   merge(arr, low, mid, high);
// }

mergeSort(head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  middle=findMiddle(head);
  leftHead=head;
  rightHead=middle->next;
  middle->next=NULL;
  leftHead=mergeSort(leftHead);
  rightHead=mergeSort(rightHead);
  return merge2(lefthead,righthead);
}

//leetcode solution:
class Solution {
public:
ListNode* findMiddle(ListNode*head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){     //T.C:O(nlogn)
    ListNode* dummyNode = new ListNode(-1);                    //S.C:O(n)
    ListNode* temp= dummyNode;
    while(list1 !=NULL && list2!=NULL){
        if(list1->val < list2->val){
           temp->next=list1;
           temp=list1;
           list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
    }
    if(list1) temp->next=list1;
    else temp->next=list2;

    return dummyNode->next;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode*middle=findMiddle(head);
        ListNode* right=middle->next;
        middle->next=nullptr;
        ListNode* left=head;

        left=sortList(left);
        right=sortList(right);
        return mergeTwoLists(left,right);
    }
};

//T.C:O(n*logn(n+n/2)
//S.C:O(1)
