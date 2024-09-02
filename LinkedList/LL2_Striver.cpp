Node* removeHead(Node*head){

    if(head==NULL){
        return head;
    }
    Node*temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, return NULL
        delete head; // Safely delete the single node if it exists
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Remove the last node
    delete temp->next;
    temp->next = NULL;

    return head; // Return the head of the updated list
}

//Delete the Kth element of the List

Node* removeFromPos(Node*head, int k){

  if(head==NULL){
    return head;
  }
  if(k==1){
    Node*temp=head;
    head=head->next;
    delete temp;
    return head;
  }
  
  //if k=3
  // i need prev 
  int count=0;
  Node*temp=head;
  Node*prev=NULL;

  while(temp){
    count++;
    if(count==k){
        prev->next=prev->next->next;
        delete(temp);
        break;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
  
}

//Insertion on head
Node* insertAtHead(Node* head, int data) {
    Node* newNode = new Node(data);  // Create a new node
    newNode->next = head;            // Point new node's next to the current head
    head = newNode;                  // Update head to point to the new node
    return head;                     // Return the new head
}


Node* insertAtTail(Node* head, int data) {
    Node* newNode = new Node(data);  // Create a new node

    if (head == nullptr) {
        // If the list is empty, the new node becomes the head
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;  // Traverse to the last node
    }
    temp->next = newNode;  // Link the last node to the new node
    return head;           // Return the head (unchanged)
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