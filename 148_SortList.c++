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
   mergeSort(leftHead);
   mergeSort(rightHead);
}
