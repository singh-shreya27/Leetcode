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


