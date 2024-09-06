Node* oddEvenList(Node* head) {
    if (head == NULL || head->next == NULL) return head; // Edge case: empty or single-node list
    
    Node* odd = new Node(-1);  //Intialize odd LL with -1
    Node* ptr = odd;           
    
    Node* even = new Node(-1); //Intialize even LL with -1
    Node* ptr2 = even;        
    
    Node* temp = head;  //put temp on head
    int count = 1;      //count=1;

    while (temp) {     //Jab tak temp null nhi hota
        if (count % 2 != 0) {
            ptr->next = temp;  // Add to odd list
            ptr = ptr->next;   // Move pointer
        } else {
            ptr2->next = temp; // Add to even list
            ptr2 = ptr2->next; // Move pointer
        }
        temp = temp->next;
        count++;
    }
    //odd= -1->1->5  ptr
    //even= -1->3->7  ptr2
    
    ptr->next = even->next;   // Connect odd list with even list
    ptr2->next = NULL;        // Terminate the even list

    return odd->next;         // Return the new head (skipping the dummy node)
}
