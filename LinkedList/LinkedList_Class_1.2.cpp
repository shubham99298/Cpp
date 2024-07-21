#include <iostream>
using namespace std;
// insert at position
class Node
 {
public:

int data;
Node*next;

//constructor creation
Node(){
  this->data=0;
  this->next=NULL;
}

Node(int data){
   this->data=data;
  this->next=NULL;
    }

 // ~Node(int data){
   
 // }
};

void print(Node*&head){

  Node* temp=head;

  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }

  
}
int findlength(Node*&head){
  int len=0;
  Node*temp=head;
  while(temp!=NULL){
    temp=temp->next;
    len++;
  }
  return len;
}

void insertatHead(Node *&head,Node *&tail, int data)

{
  // NULL WALA CASE
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
    return;
  }

  
  
  //step1 : create new node
   Node*newNode= new Node(data);
  //step 2: point new node next to head
  newNode->next=head;
  //step 3: attach head to new node

  head=newNode;
  
  
}

void insertAtTail( Node *&head,Node *&tail, int data){
  
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
    return;
  }
  //step1:
  Node*newNode= new Node(data);

 tail->next=newNode;
  
  tail=newNode;
  
  
}

 void insertAtPosition(int pos,Node*&head, Node* &tail , int data){

  if(head==NULL){
    Node*newNode=new Node(data);

    head=newNode;
    tail=newNode;
    return;
  }

   
   if(pos==0){
     insertatHead(head, tail,data);
     return;
     
   }
     
   int len=findlength(head);
   
   if(pos>=len)
   {
     insertAtTail(head,tail,data);
     return;
     
   }
   //step1 : find position : prev and curr;
   int i=1;
    Node*prev=head;
   while(i<pos){
     prev=prev->next;
     i++;  
   }
   Node*curr=prev->next;
   
    //setp 2:
   Node*newNode=new Node(data);
   //step3:
   newNode->next=curr;

   //step 4:
   prev->next=newNode;
   
  
}

void deleteAtPos(int pos, Node*&head, Node*&tail){

  if(head==NULL){
    cout<<"cannot delete";
    return;
  }

  if(pos==1){
    Node*temp=head;
    head=head->next;
    temp->next=NULL;
    delete(temp);
    return;
  }

  int len=findlength(head);
  if(pos==len){

    int i=1;
    Node*prev=head;
    while(i<pos-1){
      prev=prev->next;
      i++;
    }

    prev->next=NULL;
    Node*temp=tail;
    tail=prev;
    delete(temp);
    return;
  }
  //deleteing middle node

  int i=1;
  Node*prev=head;
  while(i<pos){
    prev=prev->next;
    i++;
    
  }
  Node*curr=prev->next;

  prev->next=curr->next;
  curr->next=NULL;
  delete curr;

  
}

int main() {

  Node *head=NULL;
  Node*tail=NULL;
  insertatHead(head,tail,20);
   insertatHead(head,tail,40);
  insertAtTail(head, tail,30);

  insertAtPosition(2,head,tail,101);
  deleteAtPos(2,head,tail);
  print(head);

  
}