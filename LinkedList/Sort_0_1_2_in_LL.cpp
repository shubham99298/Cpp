lass Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        

        // Add code here
        Node*zero=new Node(-1);
        Node*ptr1=zero;
        
        Node*one= new Node(-1);
        Node*ptr2=one;
        
        Node*Two= new Node(-1);
        Node*ptr3=Two;
        
        Node*temp=head;
        while(temp){
            
            if(temp->data==0){
                zero->next=temp;
                ptr1=ptr1->next;
            }
            if(temp->data==1){
                one->next=temp;
                ptr2=ptr2->next;
            }
            if(temp->data==2){
                Two->next=temp;
                ptr3=ptr3->next;
            }
            temp=temp->next;
        }
        ptr1->next = (one->next) ? one->next : Two->next;  // Connect 0's list to 1's list if it exists, otherwise to 2's list
        ptr2->next = Two->next;  // Connect 1's list to 2's list
        ptr3->next = nullptr;  // End of the list
        return zero->next;
    }
};
