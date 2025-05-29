   //Find the intersection point of Y LL.

//4 METHODS 
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

 //Brute force approach:
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
      data=data1;
      next=NULL;
    }
};
//function to insert node at the end of the LL
void insertNode(Node* &head, int data1){
    Node *newNode=new Node(data1);
    if(head==NULL){
        head=newNode;
        return;
    }

    Node*temp=head;
    while(temp->next!=NULL) 
    temp=temp->next;

    temp->next=newNode;
    return;
}
//function to check presence of intersection
Node* intersectionPresent(Node* head1, Node* head2){
    while(head2!=NULL){
        Node*temp=head1;
        while(temp!=NULL){
            //if both nodes same
            if(temp==head2) return head2;
            temp=temp->next;
        }
        head2=head2->next;
    }
    //intersection is not present between the LL return NULL
    return NULL;
}

//function to print LL created
void printList(Node* head){
    while(head->next!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<head->data<<endl;
}
int main(){
    //creation of both lists
    Node* head=NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1=head;
    head=head->next->next->next;
    Node* headSec = NULL;
    insertNode(headSec, 3);
    Node* head2= headSec;
    headSec->next=head;

    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);

    //checking if intersection is present
    Node* answerNode= intersectionPresent(head1, head2);
    if(answerNode==NULL) 
    cout<<"No intersection";
    else 
    cout<<"The intersection point is: "<< answerNode->data<<endl;

    return 0;
}

//T.C:O(N*M)
//S.C:O(1)


//Hashing: takes O(1) time complexity


#include<bits/stdc++.h>
using namespace std;
    class Node{
        public:
        int data;
        Node* next;
        Node(int data1){
            data=data1;
            next=NULL;
        }
    };

        //function to insert node at the end of LL
        void insertNode(Node* &head, int data1){
           Node* newNode= new Node(data1);
           if(head==NULL){
            head=newNode;
            return;
           }
           Node* temp=head;
           while(temp->next!=NULL) 
           temp=temp->next;

           temp->next=newNode;
           return;
        }
       //function to check presence of intersection
       Node* intersectionPresent(Node* head1, Node* head2){
        unordered_set<Node*> st;
        while(head1!=NULL){
            st.insert(head1);
            head1=head1->next;
        }
        while(head2!=NULL){
            if(st.find(head2) != st.end()) return head2;
            head2=head2->next;
        }
         return NULL;
       }
       //function to print LL 
       void printList(Node*head){
        while(head->next!=NULL){
            cout<<head->data<<"->";
            head=head->next;
        }
        cout<<head->data<<endl;
       }
int main(){
    //creation of both lists
    Node*head=NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node*head1=head;
    head=head->next->next->next;
    Node*headSec=NULL;
    insertNode(headSec,3);
    Node*head2=headSec;
    headSec->next=headSec;
    headSec->next=head;
    //printinf of lists
    cout<<"List1: "; 
    printList(head1);
    cout<<"List2: "; 
    printList(head2);

    //check if intersection is present
    Node* answerNode=intersectionPresent(head1, head2);
         if(answerNode==NULL) 
    cout<<"No intersection";
    else 
    cout<<"The intersection point is: "<< answerNode->data<<endl;

    return 0;
}
//T.C:O(n+m)
//S.C:O(n)

//METHOD 3: DIFFERENCE IN LENGTH
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data=data1;
        next=NULL;
    }
};

void insertNode(Node*&head, int data1){
    Node* newNode=new Node(data1);

    if(head==NULL){
        head= newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return;
}
int getDifference(Node*head1, Node*head2){
    int len1=0, len2=0;
    while(head1!=NULL || head2!=NULL){
        if(head1!=NULL){
            ++len1;
            head1=head1->next;
        }
        if(head2!=NULL){
            ++len2;
            head2=head2->next;
        }
    }
    return len1-len2; //if diff neg : length of list2> length of list1
}

//check presence of intersection
Node* intersectionPoint(Node* head1, Node* head2){
    int diff= getDifference(head1, head2);
    if(diff<0){
        while(diff++!=0)
        head2=head2->next;
    }
    else {
        while(diff-- !=0)
        head1=head1->next;
    }
    while(head1 !=NULL){

        if(head1==head2) return head1;
        head2=head2->next;
        head1=head1->next;
    }
     return head1;   
}
//print the list
void printList(Node* head){
    while(head->next!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<head->data<<endl;
}
int main(){
    Node*head=NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1=head;
    head=head->next->next->next;
    Node*headSec =NULL;
    insertNode(headSec,3);
    Node* head2=headSec;
    headSec->next=head;

    //print the list
    cout<<"List1:";
    printList(head1);
    cout<<"List2:";
    printList(head2);
    //check if intersection is present
    Node* answerNode= intersectionPoint(head1, head2);
    if(answerNode==NULL)
    cout<<"No intersection";
    else 
    cout<<"The intersection point is:"<<answerNode->data<<endl;
     
    return 0;
}
//T.C:O(2 max(len of list1, len f list2)+O(abs(len of list1-len of list2))+O(min(len of list1, len of list2)))
//Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them. 
//Moving the head pointer ahead by a difference of them. The next one is for searching.

//S.C:O(1)

//OPTIMAL APPROACH:
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int data1){
        data=data1;
        next=NULL;
    }
};
//insert node at the end of the LL
void insertNode(Node* & head, int data1){
    Node* newNode= new Node(data1);

    if(head==NULL){
        head= newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;

    temp->next= newNode;
    return;
}

//check presence of intersection
Node* intersectionPoint(Node* head1, Node* head2){
    Node* d1= head1;
    Node* d2= head2;
    while(d1!=d2){
        d1=d1==NULL ? head2:d1->next;
       // If d1 reaches the end of head1 (i.e., d1 becomes NULL), 
       //it is redirected to start traversing head2 (d1 = head2).
        d2=d2==NULL ? head1:d2->next;
    }
    return d1;
}

//print LL
void printList(Node* head){
    while(head->next!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<head->data<<endl;
}
int main(){
    //creation of both list
    Node* head= NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1=head;
    head=head->next->next->next;
    Node* headSec=NULL;
    insertNode(headSec,3);
    Node* head2=headSec;
    headSec->next=head;
    //print the list
    cout<<"List1:";
    printList(head1);
    cout<<"List2:";
    printList(head2);
    //check if intersection is present
    Node* answerNode= intersectionPoint(head1,head2);
    if(answerNode==NULL)
    cout<<"No intersection";
    else
    cout<<"The intersection point is"<<answerNode->data<<endl;

    return 0;
}

//T.C:O(2*max(length of list1, length of list2))
//S.C:o(1)
