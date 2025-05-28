   //Find the intersection point of Y LL.

//Brute force approach:
//Using hashing , store all the nodes of first LL, then go through second LL, if any node is visited again then that will be the intersecting point.

//Store the node(not the key)

map<Node,int> mpp;
temp=head1;
while(temp!=NULL){
  mpp[temp]=1;                   //O(n1*log n)
  temp=temp->next;      
}
temp=head2;
while(temp!=NULL){
  if(mpp.find(temp)==tick){             //O(n2*logn)
    return true;           
  }
  temp=temp->next;
}
return NULL;

//T.C:O(n1* )+O(n2* ) 
//S.C:O(n1) or O(n2) //depending on which LL we are storing. //optimise

//WE CANNOT STORE THE NODES ..SOLVE IT DURING THE TRAVERSAL ITSELF.
//take t1 and t2 and compute the lengths of both the LL.(n1 and n2)

 
